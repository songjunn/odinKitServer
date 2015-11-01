#include "RobotNet.h"
#include "Packet.h"
#include "RobotObj.h"
#include "curl.h"

bool CRobotNet::shutdown(SOCKET sock)
{
    return CNet::shutdown(sock);
}

int CRobotNet::sendMsg(int64 uid, SOCKET s, PACKET_COMMAND* pack)
{
    pack->SetTrans(uid);

    return CNet::send(s, (char*)pack->Data(), pack->Size());
}

bool CRobotNet::handlePacket(PACKET_COMMAND * pack)
{
    m_PackLock.LOCK();
    m_PacketList.AddToTail(pack);
    m_PackLock.UNLOCK();

    return true;
}

PACKET_COMMAND*	 CRobotNet::getHeadPacket()
{
    PACKET_COMMAND* pack = NULL;
    m_PackLock.LOCK();
    if (m_PacketList.Count() > 0) {
        pack = m_PacketList.Head();
        m_PacketList.RemoveFromHead();
    }
    m_PackLock.UNLOCK();
    return pack;
}

bool CRobotNet::sendHttpRequest(CRobotObj *robot)
{
    string postStr = "action=1&platform=0&guest="+robot->GetUserName();
    string authUrl = "119.29.22.222:1313";

    CURL *pUrl = curl_easy_init();
    curl_easy_setopt(pUrl, CURLOPT_URL, authUrl.c_str());
    curl_easy_setopt(pUrl, CURLOPT_POSTFIELDS, postStr.c_str());
    curl_easy_setopt(pUrl, CURLOPT_WRITEFUNCTION, recvHttpResponse);
    curl_easy_setopt(pUrl, CURLOPT_WRITEDATA, robot);
    curl_easy_setopt(pUrl, CURLOPT_POST, 1);
    curl_easy_setopt(pUrl, CURLOPT_NOSIGNAL, 1);
    //curl_easy_setopt(pUrl, CURLOPT_VERBOSE, 1);
    //curl_easy_setopt(pUrl, CURLOPT_HEADER, 1);
    //curl_easy_setopt(pUrl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(pUrl, CURLOPT_COOKIEFILE, "curlauth.cookie");
    CURLcode res = curl_easy_perform(pUrl);
    curl_easy_cleanup(pUrl);

    return (res == 0);
}

size_t CRobotNet::recvHttpResponse(void *buffer, size_t nsize, size_t nmemb, void *userp)
{
    CRobotObj *robot = (CRobotObj *)userp;
    char *recvdata = (char *)buffer;

    return nsize * nmemb;
}


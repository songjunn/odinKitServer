import web
import datetime
import time
import pymongo
import string
import GMWeb
from pymongo import MongoClient

format_date = "%Y-%m-%d"
format_datetime = "%Y-%m-%d %H:%M:%S"
conn = pymongo.MongoClient('localhost', 27017)
db = conn.odin_gamedb_024

def connectDB(serverID):
    global conn
    global db
#    print GMWeb.confDic[serverID]
    intPort = string.atoi(GMWeb.confDic[serverID][3][1])
#    print GMWeb.confDic[serverID][2][1]
#    print intPort
#    print GMWeb.confDic[serverID][1][1]
    database = GMWeb.confDic[serverID][1][1]
#    print database
    conn = pymongo.MongoClient(GMWeb.confDic[serverID][2][1], intPort)
    db = conn[database]

def get_posts():
    return db.entries.find()

def get_PlayerInfos(serverID):
#    intPort = string.atoi(GMWeb.confDic[serverID][3][1])
#    conn = pymongo.MongoClient(GMWeb.confDic[serverID][2][1], intPort)
#    db = conn.GMWeb.confDic[serverID][1][1]

    connectDB(serverID)
#    for i in db.player.find({},{"playerid":1, "name":1, "level":1, "fighting":1}):
#        print i['name']
    return db.player.find({},{"playerid":1, "name":1, "level":1, "fighting":1})

def get_PlayerInfo(playerID, serverID):
    intPlayerID = string.atoi(playerID)
    connectDB(serverID)
    return db.player.find({"playerid":intPlayerID})

def get_CurrItem(playerID, serverID):
    intPlayerID = string.atoi(playerID)
    connectDB(serverID)
    return db.item.find({'playerid':intPlayerID})

def get_MyHeroes(playerID, serverID):
    intPlayerID = string.atoi(playerID)
    connectDB(serverID)
    return db.hero.find({"playerid":intPlayerID})

def get_ServerInfo(secs):
    for i in range(len(secs)):
        connectDB(secs[i])
        serverInfos=db.serverInfo.find_one()
        GMWeb.serverInfoDic[secs[i]] = serverInfos

def getDateElements(sdate):
    dformat = format_date
    sdate = time.strptime(sdate, dformat)
    return sdate

def getCurrDate():
     currDate = time.localtime()
     stringYear ='%d' %currDate[0]
     stringMonth = '%d' %currDate[1]
     stringDate = '%d' %currDate[2]
     stringCurrDate = stringYear + "-" + stringMonth + "-" + stringDate
     return stringCurrDate
#    return time.strftime(format_date, time.localtime(time.time()))

def getCurrentDateX():
    return time.strftime(format_date, time.localtime(time.time()))
    
def dateAddInDays(date1, addcount):
    try:
        addtime=datetime.timedelta(days=int(addcount))
        d1Elements=getDateElements(date1)
        d1 = datetime.datetime(d1Elements.tm_year, d1Elements.tm_mon, d1Elements.tm_mday)
        datenew=d1+addtime
        stringYear ='%d' %datenew.year
        stringMonth = '%d' %datenew.month
        stringDate = '%d' %datenew.day
        stringCurrDate = stringYear + "-" + stringMonth + "-" + stringDate
        return stringCurrDate
#        return datenew.strftime(format_date)
    except Exception as e:
        print e
        return None
   
def get_AnalyseLoginInfo(serverID):
    currDate = getCurrDate()
    startTime = currDate + " 00:00:00"
    endTime = currDate + " 23:59:59"
    loginDic = {}
    connectDB(serverID)
    registerCount = db.event.find({"$and":[{"time":{"$gte":startTime}},{"time":{"$lte":endTime}},{"evid":6}]}).count()
    loginCount = db.event.find({"$and":[{"time":{"$gte":startTime}},{"time":{"$lte":endTime}},{"evid":1}]}).count()
    loginDic['registerCount'] = registerCount
    loginDic['loginCount'] = loginCount
    return loginDic

def get_AnalyseRechargeUserInfo(serverID):
    connectDB(serverID)
    currDate = getCurrDate()
    startTime = currDate + " 00:00:00"
    endTime = currDate + " 23:59:59"
    return db.event.find({"$and":[{"time":{"$gte":startTime}},{"time":{"$lte":endTime}},{"evid":700}]}, {"role":1, "param1":1})

def get_AnalyseRechargeInfo(serverID):
    payDic = {}
    currDate = getCurrDate()
    startTime = currDate + " 00:00:00"
    endTime = currDate + " 23:59:59"
    connectDB(serverID)
    loginCount = db.event.find({"$and":[{"time":{"$gte":startTime}},{"time":{"$lte":endTime}},{"evid":1}]}).count()
    payUserCount = db.event.find({"$and":[{"time":{"$gte":startTime}},{"time":{"$lte":endTime}},{"evid":700}]}).count()
    pipeline = [{'$match':{'$and':[{'time':{'$gte':startTime}},{'time':{'$lte':endTime}},{'evid':700}]}}, {'$group':{'_id':'$evid','payCount':{'$sum':'$param1'}}}]
    aggregateResult = db.event.aggregate(pipeline)
    payDic['loginCount'] = loginCount
    payDic['payCount'] = 0
    for aggregate in aggregateResult:
        payDic['payCount'] = aggregate['payCount']

    payDic['payUserCount'] = payUserCount
    return payDic

def get_SingleAnalyseSaveInfo(currDate, dateX):
    countX = 0
    countN = 0
    startTime = currDate + " 00:00:00"
    endTime = currDate + " 23:59:59"

    startTimeX = dateX + " 00:00:00"
    endTimeX = dateX + " 23:59:59"
    roleArray = db.event.find({"$and":[{"time":{"$gte":startTimeX}},{"time":{"$lte":endTimeX}},{"evid":6}]},{"role":1})
    for singleRole in roleArray:
      roleID = singleRole['role']
      countN += db.event.find({"$and":[{"time":{"$gte":startTime}},{"time":{"$lte":endTime}},{"evid":1},{"role":roleID}]},{"role":1}).count()

    countX = db.event.find({"$and":[{"time":{"$gte":startTimeX}},{"time":{"$lte":endTimeX}},{"evid":6}]},{"role":1}).count()
    if(0 == countX):
        singleSaveInfo = 0
    else:
        singleSaveInfo = countN/countX
    
    return singleSaveInfo

def get_AnalyseSaveInfo(serverID):
    serverInfo = []
    currDate = getCurrDate()
    date1 = dateAddInDays(currDate, -1)
    date2 = dateAddInDays(currDate, -2)
    date3 = dateAddInDays(currDate, -3)
    date4 = dateAddInDays(currDate, -4)
    date5 = dateAddInDays(currDate, -5)
    date6 = dateAddInDays(currDate, -6)
    
    connectDB(serverID)
    serverInfo.append(get_SingleAnalyseSaveInfo(currDate, date1))
    serverInfo.append(get_SingleAnalyseSaveInfo(currDate, date2))
    serverInfo.append(get_SingleAnalyseSaveInfo(currDate, date3))
    serverInfo.append(get_SingleAnalyseSaveInfo(currDate, date4))
    serverInfo.append(get_SingleAnalyseSaveInfo(currDate, date5))
    serverInfo.append(get_SingleAnalyseSaveInfo(currDate, date6))
    
    print serverInfo
    return serverInfo

#-*-coding:utf-8-*-i
import web
import model
import ConfigParser
import string, os, sys

urls = (
	'/', 'Login',
	'/index', 'Index',
        '/playerInfos/(.+)', 'PlayerInfos',
#        '/userAnalyse/(.+)', 'UserAnalyse',
        '/playerInfo/(.+)/(.+)', 'PlayerInfo',
        '/currItem/(.+)/(.+)', 'CurrItem',
        '/myHeroes/(.+)/(.+)', 'MyHeroes',
        '/heroesItem/(.+)/(.+)', 'HeroesItem',
        '/packageInfo/(.+)/(.+)', 'PackageInfo',
        '/formationInfo/(.+)/(.+)', 'FormationInfo',
        '/userAnalyse/(.+)/logInInfo', 'AlogInInfo',
        '/userAnalyse/(.+)/rechargeUserInfo', 'ArechargeUserInfo',
        '/userAnalyse/(.+)/rechargeInfo', 'ArechargeInfo',
        '/userAnalyse/(.+)/saveInfo', 'AsaveInfo',
        '/downloadFiles', 'DownloadFiles',
        '/root/GMWeb/downloadFiles/(.+)', 'Download',
        '/logout', 'Logout'
       )

app = web.application(urls, globals())

t_globals = {
	'datestr': web.datestr,
	'cookie': web.cookies,
}

BUF_SIZE = 262144
confDic = {}
secs = []
serverInfoDic = {}
render = web.template.render('templates', globals = t_globals)
t_globals['render'] = render
t_globals['confDic'] = confDic
t_globals['secs'] = secs
t_globals['serverInfoDic'] = serverInfoDic
login = web.form.Form(
		     web.form.Textbox('username', description = '用户名'),
		     web.form.Password('password', description = '密码'),
		     web.form.Button('login',type = 'submit', html = '登录')
		     )

class Login:
    def GET(self):
	login_form = login()
        posts = model.get_posts()
        return render.login(posts, login_form)

    def POST(self):
        login_form = login()
        if login_form.validates():
           if login_form.d.username == 'admin' and login_form.d.password == 'admin':
               web.setcookie('username', login_form.d.username)
               raise web.seeother('/index')
        raise web.seeother('/')

class Index:
    def GET(self):
        print secs
        print confDic
        return render.index()

    def POST(self):
        return 'Index POST'

    def __init__(self):
        cf = ConfigParser.ConfigParser()
        cf.read("GMWeb.conf")
        secs = cf.sections()
        t_globals['secs'] = cf.sections()

        for i in range(len(secs)):
           kvs = cf.items(secs[i])
           confDic[secs[i]] = kvs
           t_globals['confDic'][secs[i]] = kvs
#        print t_globals['confDic']
#        print secs

        model.get_ServerInfo(secs)
        return

class PlayerInfos:
    def GET(self, serverID):
        playerInfos = model.get_PlayerInfos(serverID)
#        playerInfos = selfmodel.get_PlayerInfos()
#        for playerInfo in playerInfos:
#            print playerInfo['name']
        return render.PlayerInfos(playerInfos, serverID)
   
    def POST(self):
        return 'Players POST'

class UserAnalyse:
    def GET(self, serverID):
        return render.UserAnalyse(serverID)

    def POST(self):
        return 'UserAnalyse'

class AlogInInfo:
    def GET(self, serverID):
        loginDic = model.get_AnalyseLoginInfo(serverID)
        return render.AlogInInfo(serverID, loginDic)

class ArechargeUserInfo:
    def GET(self, serverID):
        rechargeUsersInfo = model.get_AnalyseRechargeUserInfo(serverID)
        return render.ArechargeUserInfo(rechargeUsersInfo, serverID)

class ArechargeInfo:
    def GET(self, serverID):
        payInfoDic = {}
        payDic = model.get_AnalyseRechargeInfo(serverID)
        if(0 == payDic['loginCount']):
            payRate = 0
        else:
            payRate = payDic['payUserCount']/payDic['loginCount']
        
        if(0 == payDic['loginCount']):
            Arpu = 0
        else:
            Arpu = payDic['payCount']/payDic['loginCount']
        
        if(0 == payDic['payUserCount']):
            Arppu = 0
        else:
            Arppu = payDic['payCount']/payDic['payUserCount']

        payInfoDic['payRate'] = payRate
        payInfoDic['Arpu'] = Arpu
        payInfoDic['Arppu'] = Arppu
        return render.ArechargeInfo(serverID, payInfoDic)

class AsaveInfo:
    def GET(self, serverID):
        saveInfo = model.get_AnalyseSaveInfo(serverID)
        return render.AsaveInfo(saveInfo, serverID)
        

class PlayerInfo():
    def GET(self, playerID, serverID):
        playerInfo = model.get_PlayerInfo(playerID, serverID)
        return render.PlayerInfo(playerInfo, playerID, serverID)

class CurrItem:
    def GET(self, playerID, serverID):
        currItemArray = model.get_CurrItem(playerID, serverID)
        return render.currItem(currItemArray, playerID, serverID)
        
    def POST(self):
        return 'CurrItem POST'
           
class MyHeroes:
    def GET(self, playerID, serverID):
        myHeroesArrays = model.get_MyHeroes(playerID, serverID)
        return render.myHeroes(myHeroesArrays, playerID, serverID)

    def POST(self):
        return 'MyHeroes POST'

class HeroesItem:
    def GET(self, playerID, serverID):
        return render.heroesItem(playerID, serverID)

    def POST(self):
        return 'Heroes POST'

class PackageInfo:
    def GET(self, playerID, serverID):
        packageInfoArrays = model.get_CurrItem(playerID, serverID)
        return render.packageInfo(packageInfoArrays, playerID, serverID)

    def POST(self):
        return 'PackageInfo POST'

class FormationInfo:
    def GET(self, playerID, serverID):
        playerInfo = model.get_PlayerInfo(playerID, serverID)
        return render.formationInfo(playerInfo, playerID, serverID)

    def POST(self):
        return 'FormationInfo POST'

class DownloadFiles:
    def GET(self):
        path = sys.path[0]
        downloadPath = path + "/downloadFiles/"
        fileList = os.listdir(downloadPath)
        print fileList
        return render.downloadFiles(downloadPath, fileList)

class Download:
    def GET(self, fileName):
        file_name = fileName
        path = sys.path[0]
        downloadPath = path + "/downloadFiles/"
        file_path = os.path.join(downloadPath, file_name)
        print file_path
        f = None
        try:
            f = open(file_path, "rb")
            web.header('Content-Type','application/octet-stream')
            web.header('Content-disposition', 'attachment; filename=%s' % file_name)
            while True:
                c = f.read(BUF_SIZE)
                if c:
                    yield c
                else:
                    break
        except Exception, e:
            print e
            yield 'Error'
        finally:
            if f:
                f.close()

class Logout:
    def GET(self):
        web.setcookie('username', '', expires = -1)
        raise web.seeother('/')

def notfound1():
    return web.notfound("Sorry, the page you were looking for was not found.")

app.notfound = notfound1

if __name__ == '__main__':
    app.run()
 

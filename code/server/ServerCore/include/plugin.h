#ifndef _PLUGIN_H_
#define _PLUGIN_H_

class CPluginHandler;
class CPlugin
{
public:
	CPlugin() {}
	virtual ~CPlugin() {}

	virtual bool startup() { return false; }
	virtual bool shutdown() { return false; }

	void sethandler(CPluginHandler* handler) {
		m_handler = handler;
	}

protected:
	CPluginHandler* m_handler;

};

#endif //_PLUGIN_H_

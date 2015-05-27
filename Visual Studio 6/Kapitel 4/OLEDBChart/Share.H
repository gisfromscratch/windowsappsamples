// Share.H : Deklaration der Klasse CShare

#ifndef __SHARE_H_
#define __SHARE_H_

class CShareAccessor
{
public:
	TCHAR m_Aktienname[51];
	LONG m_Aktiennummer;
	TCHAR m_Tickersymbol[7];
	LONG m_WKN;

BEGIN_COLUMN_MAP(CShareAccessor)
	COLUMN_ENTRY(1, m_Aktiennummer)
	COLUMN_ENTRY(2, m_Aktienname)
	COLUMN_ENTRY(3, m_WKN)
	COLUMN_ENTRY(4, m_Tickersymbol)
END_COLUMN_MAP()

DEFINE_COMMAND(CShareAccessor, _T(" \
	SELECT \
		Aktiennummer, \
		Aktienname, \
		WKN, \
		Tickersymbol  \
		FROM Aktie"))

	// Sie können diese Funktion aufrufen, wenn Sie einen Datensatz einfügen und Sie
	// alle Felder initialisieren wollen, wenn Sie nicht alle von diesen explizit setzen.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

extern COLEDBChartApp theApp;

class CShare : public CCommand<CAccessor<CShareAccessor> >
{
public:
	HRESULT Open()
	{
		HRESULT		hr;

		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;

		return OpenRowset();
	}
	HRESULT OpenDataSource()
	{
		HRESULT		hr;
		CDataSource db;
		CDBPropSet	dbinit(DBPROPSET_DBINIT);

		dbinit.AddProperty(DBPROP_AUTH_CACHE_AUTHINFO, true);
		dbinit.AddProperty(DBPROP_AUTH_ENCRYPT_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_MASK_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_PASSWORD, OLESTR(""));
		dbinit.AddProperty(DBPROP_AUTH_PERSIST_ENCRYPTED, false);
		dbinit.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
		dbinit.AddProperty(DBPROP_AUTH_USERID, OLESTR("Admin"));
		dbinit.AddProperty(DBPROP_INIT_DATASOURCE, theApp.strDBName);
		dbinit.AddProperty(DBPROP_INIT_MODE, (long)16);
		dbinit.AddProperty(DBPROP_INIT_PROMPT, (short)4);
		dbinit.AddProperty(DBPROP_INIT_PROVIDERSTRING, OLESTR(";COUNTRY=0;CP=1252;LANGID=0x0409"));
		dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);
		hr = db.Open(_T("Microsoft.Jet.OLEDB.3.51"), &dbinit);
      if (FAILED(hr))
			return hr;

		return m_session.Open(db);
	}
	HRESULT OpenRowset()
	{
		return CCommand<CAccessor<CShareAccessor> >::Open(m_session);
	}
	CSession	m_session;
};

#endif // __SHARE_H_

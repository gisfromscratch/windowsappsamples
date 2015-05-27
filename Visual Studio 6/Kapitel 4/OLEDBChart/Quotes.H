// Quotes.H : Deklaration der Klasse CQuotes

#ifndef __QUOTES_H_
#define __QUOTES_H_

class CQuotesAccessor
{
public:
	CURRENCY m_Kurs;
	TCHAR m_Aktienname[51];
	TCHAR m_Tickersymbol[7];
	LONG m_WKN;

BEGIN_COLUMN_MAP(CQuotesAccessor)
	COLUMN_ENTRY_TYPE(1, DBTYPE_CY, m_Kurs)
	COLUMN_ENTRY(2, m_Aktienname)
	COLUMN_ENTRY(3, m_Tickersymbol)
	COLUMN_ENTRY(4, m_WKN)
END_COLUMN_MAP()

	// Sie können diese Funktion aufrufen, wenn Sie einen Datensatz einfügen und Sie
	// alle Felder initialisieren wollen, wenn Sie nicht alle von diesen explizit setzen.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

extern COLEDBChartApp theApp;

class CQuotes : public CCommand<CAccessor<CQuotesAccessor> >
{
public:
	HRESULT Open(const CString& strShareName)
	{
		HRESULT		hr;

		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;

		return OpenRowset(strShareName);
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
	HRESULT OpenRowset(const CString& strShareName)
	{
      CString strSQL = _T(
         "SELECT Kurs, Aktienname, Tickersymbol, WKN "
         "FROM Kurs, Aktie "
         "WHERE Kurs.Aktiennummer = Aktie.Aktiennummer "
         "AND Aktie.Aktienname = '");
      strSQL += strShareName;
      strSQL += _T("' ORDER BY Kurs.Datum");

		return CCommand<CAccessor<CQuotesAccessor> >::Open(m_session, strSQL);
	}
	CSession	m_session;
};

#endif // __QUOTES_H_

// StockOLEDBSet.h : Schnittstelle der Klasse CStockOLEDBSet
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKOLEDBSET_H__9222C993_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
#define AFX_STOCKOLEDBSET_H__9222C993_6036_11D2_B3F3_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAktie
{
public:
		CAktie()
	{
		memset( (void*)this, 0, sizeof(*this) );
			};

	char m_Aktienname[51];
	int m_Aktiennummer;
	char m_Tickersymbol[7];
	int m_WKN;


BEGIN_COLUMN_MAP(CAktie)
		COLUMN_ENTRY_TYPE(2, DBTYPE_STR, m_Aktienname)
		COLUMN_ENTRY_TYPE(1, DBTYPE_I4, m_Aktiennummer)
		COLUMN_ENTRY_TYPE(4, DBTYPE_STR, m_Tickersymbol)
		COLUMN_ENTRY_TYPE(3, DBTYPE_I4, m_WKN)
END_COLUMN_MAP()

};

class CStockOLEDBSet : public CCommand<CAccessor<CAktie> >
{
public:

	HRESULT Open()
	{
		CDataSource db;
		CSession	session;
		HRESULT		hr;

      // Dateidialog zum Abfragen der 
      // Datenbank
      CFileDialog fileDialog(true,
                             _T("mdb"), 
                             _T("Aktien.mdb"),
                             NULL,
                             _T("MDB-Dateien (*.mdb)|*.mdb"));

      // Wenn der Benutzer den Dialog nicht mit OK verlassen hat:
      if (IDOK != fileDialog.DoModal ()) { 
         return S_FALSE; // Fehler
	   }

		CDBPropSet	dbinit(DBPROPSET_DBINIT);
		dbinit.AddProperty(DBPROP_AUTH_CACHE_AUTHINFO, true);
		dbinit.AddProperty(DBPROP_AUTH_ENCRYPT_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_MASK_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_PASSWORD, "");
		dbinit.AddProperty(DBPROP_AUTH_PERSIST_ENCRYPTED, false);
		dbinit.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
		dbinit.AddProperty(DBPROP_AUTH_USERID, "Admin");
		dbinit.AddProperty(DBPROP_INIT_DATASOURCE, fileDialog.GetPathName ());
		dbinit.AddProperty(DBPROP_INIT_MODE, (long)16);
		dbinit.AddProperty(DBPROP_INIT_PROMPT, (short)4);
		dbinit.AddProperty(DBPROP_INIT_PROVIDERSTRING, ";COUNTRY=0;CP=1252;LANGID=0x0409");
		dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);

		hr = db.OpenWithServiceComponents("Microsoft.Jet.OLEDB.3.51", &dbinit);
		if (FAILED(hr))
			return hr;

		hr = session.Open(db);
		if (FAILED(hr))
			return hr;

		CDBPropSet	propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
		propset.AddProperty(DBPROP_IRowsetScroll, true);
		propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE );

		hr = CCommand<CAccessor<CAktie> >::Open(session, "SELECT * FROM Aktie", &propset);

		if (FAILED(hr))
			return hr;

		return MoveNext();
	}

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STOCKOLEDBSET_H__9222C993_6036_11D2_B3F3_006097A8F69A__INCLUDED_)


// Von Klassen-Assistent automatisch erstellte IDispatch-Kapselungsklasse(n). 
/////////////////////////////////////////////////////////////////////////////
// Wrapper-Klasse IStockChartAuto 

class IStockChartAuto : public COleDispatchDriver
{
public:
	IStockChartAuto() {}		// Ruft den Standardkonstruktor für COleDispatchDriver auf
	IStockChartAuto(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IStockChartAuto(const IStockChartAuto& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attribute
public:
	long GetId();
	void SetId(long);
	CString GetName();
	void SetName(LPCTSTR);
	LPDISPATCH GetStatusbar();
	void SetStatusbar(LPDISPATCH);
	CString GetTicker();
	void SetTicker(LPCTSTR);
	BOOL GetAverage();
	void SetAverage(BOOL);
	long GetAveragecnt();
	void SetAveragecnt(long);
	BOOL GetGrid();
	void SetGrid(BOOL);

// Operationen
public:
	void ShowWindow();
	void SetColor(short red, short green, short blue);
	BOOL SaveFile(LPCTSTR pathName);
	BOOL ImportFile(LPCTSTR pathName);
};
/////////////////////////////////////////////////////////////////////////////
// Wrapper-Klasse IStatusBarInterface 

class IStatusBarInterface : public COleDispatchDriver
{
public:
	IStatusBarInterface() {}		// Ruft den Standardkonstruktor für COleDispatchDriver auf
	IStatusBarInterface(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IStatusBarInterface(const IStatusBarInterface& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attribute
public:
	CString GetStatus();
	void SetStatus(LPCTSTR);

// Operationen
public:
};

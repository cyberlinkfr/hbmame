// For licensing and usage information, read docs/winui_license.txt
//****************************************************************************

#ifndef TREEVIEW_H
#define TREEVIEW_H

/* corrections for commctrl.h */

#if defined(__GNUC__)
/* fix warning: cast does not match function type */
#undef  TreeView_InsertItem
#define TreeView_InsertItem(w,i) (HTREEITEM)(LRESULT)(int)SendMessage((w),TVM_INSERTITEM,0,(LPARAM)(LPTV_INSERTSTRUCT)(i))

#undef  TreeView_SetImageList
#define TreeView_SetImageList(w,h,i) (HIMAGELIST)(LRESULT)(int)SendMessage((w),TVM_SETIMAGELIST,i,(LPARAM)(HIMAGELIST)(h))

#undef  TreeView_GetNextItem
#define TreeView_GetNextItem(w,i,c) (HTREEITEM)(LRESULT)(int)SendMessage((w),TVM_GETNEXTITEM,c,(LPARAM)(HTREEITEM)(i))

#undef TreeView_HitTest
#define TreeView_HitTest(hwnd, lpht) \
    (HTREEITEM)(LRESULT)(int)SNDMSG((hwnd), TVM_HITTEST, 0, (LPARAM)(LPTV_HITTESTINFO)(lpht))

/* fix wrong return type */
#undef  TreeView_Select
#define TreeView_Select(w,i,c) (BOOL)(int)SendMessage((w),TVM_SELECTITEM,c,(LPARAM)(HTREEITEM)(i))

#undef TreeView_EditLabel
#define TreeView_EditLabel(w, i) \
    SNDMSG(w,TVM_EDITLABEL,0,(LPARAM)(i))

#endif /* defined(__GNUC__) */
#include "bitmask.h"

/***************************************************************************
    Folder And Filter Definitions
 ***************************************************************************/

typedef struct
{
	const char *m_lpTitle; // Folder Title
	const char *short_name;  // for saving in the .ini
	UINT        m_nFolderId; // ID
	UINT        m_nIconId; // if >= 0, resource id of icon (IDI_xxx), otherwise index in image list
	BOOL        m_process;
	DWORD       m_dwUnset; // Excluded filters
	DWORD       m_dwSet;   // Implied filters
	void        (*m_pfnCreateFolders)(int parent_index); // Constructor for special folders
	BOOL        (*m_pfnQuery)(int nDriver);              // Query function
	BOOL        m_bExpectedResult;                       // Expected query result
} FOLDERDATA, *LPFOLDERDATA;

typedef const FOLDERDATA *LPCFOLDERDATA;

typedef struct
{
	DWORD m_dwFilterType;				/* Filter value */
	DWORD m_dwCtrlID;					/* Control ID that represents it */
	BOOL (*m_pfnQuery)(int nDriver);	/* Query function */
	BOOL m_bExpectedResult;				/* Expected query result */
} FILTER_ITEM, *LPFILTER_ITEM;

typedef const FILTER_ITEM *LPCFILTER_ITEM;

/***************************************************************************
    Functions to build builtin folder lists
 ***************************************************************************/

void CreateManufacturerFolders(int parent_index);
void CreateYearFolders(int parent_index);
void CreateSourceFolders(int parent_index);
void CreateScreenFolders(int parent_index);
void CreateCPUFolders(int parent_index);
void CreateSoundFolders(int parent_index);
void CreateOrientationFolders(int parent_index);
void CreateDeficiencyFolders(int parent_index);
void CreateDumpingFolders(int parent_index);
void CreateBIOSFolders(int parent_index);
void CreateFPSFolders(int parent_index);
void CreateResolutionFolders(int parent_index);

/***************************************************************************/

#define MAX_EXTRA_FOLDERS 256
#define MAX_EXTRA_SUBFOLDERS 256
#define SHOW_UNAVAILABLE_FOLDER

/* TreeView structures */
enum
{
	FOLDER_NONE = 0,
	FOLDER_ALLGAMES,
	FOLDER_AVAILABLE,
#ifdef SHOW_UNAVAILABLE_FOLDER
	FOLDER_UNAVAILABLE,
#endif
	FOLDER_MANUFACTURER,
	FOLDER_YEAR,
	FOLDER_SOURCE,
	FOLDER_CPU,
	FOLDER_SND,
	FOLDER_DEFICIENCY,
	FOLDER_WORKING,
	FOLDER_NONWORKING,
	FOLDER_ORIGINAL,
	FOLDER_CLONES,
	FOLDER_RASTER,
	FOLDER_VECTOR,
	FOLDER_TRACKBALL,
	FOLDER_LIGHTGUN,
	FOLDER_STEREO,
	FOLDER_HARDDISK,
	FOLDER_SAMPLES,
	FOLDER_DUMPING,
	FOLDER_SAVESTATE,
	FOLDER_BIOS,
	FOLDER_RESOLUTION,
	FOLDER_FPS,
	FOLDER_HORIZONTAL,
	FOLDER_VERTICAL,
	FOLDER_SCREENS,
	FOLDER_MECHANICAL,
	FOLDER_NONMECHANICAL,
	MAX_FOLDERS
};

typedef enum
{
	F_CLONES        = 0x00000001,
	F_NONWORKING    = 0x00000002,
	F_UNAVAILABLE   = 0x00000004,
	F_VECTOR        = 0x00000008,
	F_RASTER        = 0x00000010,
	F_ORIGINALS     = 0x00000020,
	F_WORKING       = 0x00000040,
	F_AVAILABLE     = 0x00000080,
	F_HORIZONTAL    = 0x00000100,
	F_VERTICAL      = 0x00000200,
	F_MECHANICAL    = 0x00000400,
	F_ARCADE        = 0x00000800,
	F_MESS          = 0x00001000,
#ifdef MESS
	F_COMPUTER      = 0x00002000,
	F_CONSOLE       = 0x00004000,
	F_MODIFIED      = 0x00008000,
#endif
	F_MASK          = 0x0000FFFF,
	F_INIEDIT       = 0x00010000, // There is an .ini that can be edited. MSH 20070811
	F_CUSTOM        = 0x01000000  // for current .ini custom folders
} FOLDERFLAG;

typedef struct
{
    LPSTR m_lpTitle;              // String contains the folder name
    LPTSTR m_lptTitle;            // String contains the folder name as TCHAR*
    UINT        m_nFolderId;      // Index / Folder ID number
    int         m_nParent;        // Parent folder index in treeFolders[]
    int         m_nIconId;        // negative icon index into the ImageList, or IDI_xxx resource id
    DWORD       m_dwFlags;        // Misc flags
    LPBITS      m_lpGameBits;     // Game bits, represent game indices
} TREEFOLDER, *LPTREEFOLDER;

typedef struct
{
    char        m_szTitle[64];  // Folder Title
    UINT        m_nFolderId;    // ID
    int         m_nParent;      // Parent Folder index in treeFolders[]
    DWORD       m_dwFlags;      // Flags - Customizable and Filters
    int         m_nIconId;      // negative icon index into the ImageList, or IDI_xxx resource id
    int         m_nSubIconId;   // negative icon index into the ImageList, or IDI_xxx resource id
} EXFOLDERDATA, *LPEXFOLDERDATA;

void FreeFolders(void);
void ResetFilters(void);
void InitTree(LPCFOLDERDATA lpFolderData, LPCFILTER_ITEM lpFilterList);
void SetCurrentFolder(LPTREEFOLDER lpFolder);
UINT GetCurrentFolderID(void);

LPTREEFOLDER GetCurrentFolder(void);
int GetNumFolders(void);
LPTREEFOLDER GetFolder(UINT nFolder);
LPTREEFOLDER GetFolderByID(UINT nID);
LPTREEFOLDER GetFolderByName(int nParentId, const char *pszFolderName);

void AddGame(LPTREEFOLDER lpFolder, UINT nGame);
void RemoveGame(LPTREEFOLDER lpFolder, UINT nGame);
int  FindGame(LPTREEFOLDER lpFolder, int nGame);

void ResetWhichGamesInFolders(void);

LPCFOLDERDATA FindFilter(DWORD folderID);

bool GameFiltered(int nGame, DWORD dwFlags);
BOOL GetParentFound(int nGame);

LPCFILTER_ITEM GetFilterList(void);

void SetTreeIconSize(HWND hWnd, BOOL bLarge);
BOOL GetTreeIconSize(void);

void GetFolders(TREEFOLDER ***folders,int *num_folders);
BOOL TryRenameCustomFolder(LPTREEFOLDER lpFolder,const char *new_name);
void AddToCustomFolder(LPTREEFOLDER lpFolder,int driver_index);
void RemoveFromCustomFolder(LPTREEFOLDER lpFolder,int driver_index);

HIMAGELIST GetTreeViewIconList(void);
int GetTreeViewIconIndex(int icon_id);

void ResetTreeViewFolders(void);
void SelectTreeViewFolder(int folder_id);

#endif /* TREEVIEW_H */
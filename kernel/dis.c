#include "dis.h"

#define cpuid_(in, a, b, c, d) __asm__("cpuid": "=a" (a), "=b" (b), "=c" (c), "=d" (d) : "a" (in));

void dis_debug(void)
{
	init_com(dis.COM1, 96000, 0, 8);

	write_com(dis.COM1, cpuid.stepping);
	write_com(dis.COM1, cpuid.familie);
	write_com(dis.COM1, cpuid.modell);
	write_com(dis.COM1, cpuid.e_modell);
	write_com(dis.COM1, cpuid.e_familie);
	write_com(dis.COM1, cpuid.typ);				// Intel
	write_com(dis.COM1, cpuid.brand);
	write_com(dis.COM1, cpuid.anz_proz);
	write_com(dis.COM1, (cpuid.apic_id + 30));
	write_com(dis.COM1, cpuid.cf_size);
	
	write_com(dis.COM1, cpuid.feature_SSE3);
	write_com(dis.COM1, cpuid.feature_DTES64);	// Intel	
	write_com(dis.COM1, cpuid.feature_MONITOR);
	write_com(dis.COM1, cpuid.feature_DS_CPL);	// Intel
	write_com(dis.COM1, cpuid.feature_SMX);		// Intel
	write_com(dis.COM1, cpuid.feature_VMX);		// Intel
	write_com(dis.COM1, cpuid.feature_EST);		// Intel
	write_com(dis.COM1, cpuid.feature_TM2);		// Intel
	write_com(dis.COM1, cpuid.feature_SSSE3);
	write_com(dis.COM1, cpuid.feature_CNXT_ID);	// Intel
	
	write_com(dis.COM1, cpuid.feature_CX16);
	write_com(dis.COM1, cpuid.feature_xTPR);	// Intel
	write_com(dis.COM1, cpuid.feature_PDCM);	// Intel
	write_com(dis.COM1, cpuid.feature_DCA);		// Intel
	write_com(dis.COM1, cpuid.feature_SSE41);	// Intel
	write_com(dis.COM1, cpuid.feature_SSE42);	// Intel
	write_com(dis.COM1, cpuid.feature_x2APIC);	// Intel
	write_com(dis.COM1, cpuid.feature_MOVBE);	// Intel
	write_com(dis.COM1, cpuid.feature_POPCNT);
	write_com(dis.COM1, cpuid.feature_XSAVE);	// Intel
	
	write_com(dis.COM1, cpuid.feature_OSXSAVE);	// Intel
	write_com(dis.COM1, cpuid.feature_FPU);
	write_com(dis.COM1, cpuid.feature_VME);
	write_com(dis.COM1, cpuid.feature_DE);
	write_com(dis.COM1, cpuid.feature_PSE);
	write_com(dis.COM1, cpuid.feature_TSC);
	write_com(dis.COM1, cpuid.feature_MSR);
	write_com(dis.COM1, cpuid.feature_PAE);
	write_com(dis.COM1, cpuid.feature_MCE);
	write_com(dis.COM1, cpuid.feature_CX8);
	
	write_com(dis.COM1, cpuid.feature_APIC);
	write_com(dis.COM1, cpuid.feature_SEP);
	write_com(dis.COM1, cpuid.feature_MTRR);
	write_com(dis.COM1, cpuid.feature_PGE);
	write_com(dis.COM1, cpuid.feature_MCA);	
	write_com(dis.COM1, cpuid.feature_CMOV);
	write_com(dis.COM1, cpuid.feature_PAT);
	write_com(dis.COM1, cpuid.feature_PSE36);
	write_com(dis.COM1, cpuid.feature_PSN);		// Intel
	write_com(dis.COM1, cpuid.feature_CLFLSH);
	
	write_com(dis.COM1, cpuid.feature_DS);		// Intel
	write_com(dis.COM1, cpuid.feature_ACPI);	// Intel
	write_com(dis.COM1, cpuid.feature_MMX);
	write_com(dis.COM1, cpuid.feature_FXSR);
	write_com(dis.COM1, cpuid.feature_FFXSR);
	write_com(dis.COM1, cpuid.feature_SSE);
	write_com(dis.COM1, cpuid.feature_SSE2);
	write_com(dis.COM1, cpuid.feature_SS);		// Intel
	write_com(dis.COM1, cpuid.feature_HTT);
	write_com(dis.COM1, cpuid.feature_TM);		// Intel
	
	write_com(dis.COM1, cpuid.feature_IA64);	// Intel
	write_com(dis.COM1, cpuid.feature_CMPL);	// AMD
	write_com(dis.COM1, cpuid.feature_MME);		// AMD
	write_com(dis.COM1, cpuid.feature_SVM);		// AMD
	write_com(dis.COM1, cpuid.feature_EAS);		// AMD
	write_com(dis.COM1, cpuid.feature_AMC8);	// AMD
	write_com(dis.COM1, cpuid.feature_ABM);		// AMD
	write_com(dis.COM1, cpuid.feature_SSE4A);	// AMD
	write_com(dis.COM1, cpuid.feature_MAS);		// AMD
	write_com(dis.COM1, cpuid.feature_3DNP);	// AMD
	write_com(dis.COM1, cpuid.feature_OSVW);	// AMD
	write_com(dis.COM1, cpuid.feature_IBS);		// AMD
	write_com(dis.COM1, cpuid.feature_SSE5);	// AMD
	write_com(dis.COM1, cpuid.feature_SKINIT);	// AMD
	write_com(dis.COM1, cpuid.feature_WDT);		// AMD
	write_com(dis.COM1, cpuid.feature_CMP8GB);	// AMD
	write_com(dis.COM1, cpuid.feature_P1GB);	// AMD
	write_com(dis.COM1, cpuid.feature_RDTSCP);	// AMD
	write_com(dis.COM1, cpuid.feature_3DNE);	// AMD
	write_com(dis.COM1, cpuid.feature_3DN);		// AMD
}

void dis_init(void)
{
	struct bda_t *BDA;
	BDA = (struct bda_t *) 0x0400;
	
	dis.COM1 = BDA->IO_COM1;


	unsigned int max;
	unsigned int eax, ebx, ecx, edx;

	cpuid_(0x00000000, max, ebx, ecx, edx);
	if( ebx == 0x756e6547 && edx == 0x49656e69  && ecx == 0x6c65746e )// GenuineIntel
	{
		cpuid.vendor[0] = 'I'; cpuid.vendor[1] = 'n'; cpuid.vendor[2] = 't'; cpuid.vendor[3] = 'e'; cpuid.vendor[4] = 'l'; cpuid.vendor[5] = '\0';
		cpuid.vendor_s[2] = 'G'; cpuid.vendor_s[1] = 'e'; cpuid.vendor_s[2] = 'n'; cpuid.vendor_s[3] = 'u'; cpuid.vendor_s[4] = 'i'; cpuid.vendor_s[5] = 'n'; cpuid.vendor_s[6] = 'e'; cpuid.vendor_s[7] = 'I'; cpuid.vendor_s[8] = 'n'; cpuid.vendor_s[9] = 't'; cpuid.vendor_s[10] = 'w'; cpuid.vendor_s[11] = 'l'; cpuid.vendor_s[12] = '\0';
		
		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = (eax & 0x00003000) >> 12;		// Intel
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}
		
		if((ecx & 3) == 3)
		{
			cpuid.feature_DTES64 = 'J';	// Intel
		}
		else 
		{
			cpuid.feature_DTES64 = 'N';
		}
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		if((ecx & 5) == 5)
		{
			cpuid.feature_DS_CPL = 'J';	// Intel
		}
		else 
		{
			cpuid.feature_DS_CPL = 'N';
		}
		
		if((ecx & 6) == 6)
		{
			cpuid.feature_SMX = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_SMX = 'N';
		}
		
		if((ecx & 7) == 7)
		{
			cpuid.feature_VMX = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_VMX = 'N';
		}
		
		if((ecx & 8) == 8)
		{
			cpuid.feature_EST = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_EST = 'N';
		}
		
		if((ecx & 9) == 9)
		{
			cpuid.feature_TM2 = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_TM2 = 'N';
		}
		
		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';
		}
		
		if((ecx & 11) == 11)
		{
			cpuid.feature_CNXT_ID = 'J';	// Intel
		}
		else 
		{
			cpuid.feature_CNXT_ID = 'N';
		}
		
		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		if((ecx & 15) == 15)
		{
			cpuid.feature_xTPR = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_xTPR = 'N';
		}
		
		if((ecx & 16) == 16)
		{
			cpuid.feature_PDCM = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_PDCM = 'N';
		}
		
		if((ecx & 19) == 19)
		{
			cpuid.feature_DCA = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_DCA = 'N';
		}
		
		if((ecx & 20) == 20)
		{
			cpuid.feature_SSE41 = 'J';	// Intel
		}
		else 
		{
			cpuid.feature_SSE41 = 'N';
		}
		
		if((ecx & 21) == 21)
		{
			cpuid.feature_SSE42 = 'J';	// Intel
		}
		else 
		{
			cpuid.feature_SSE42 = 'N';
		}
		
		if((ecx & 22) == 22)
		{
			cpuid.feature_x2APIC = 'J';	// Intel
		}
		else 
		{
			cpuid.feature_x2APIC = 'N';
		}
		
		if((ecx & 23) == 23)
		{
			cpuid.feature_MOVBE = 'J';	// Intel
		}
		else 
		{
			cpuid.feature_MOVBE = 'N';
		}
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		if((ecx & 27) == 27)
		{
			cpuid.feature_XSAVE = 'J';	// Intel
		}
		else 
		{
			cpuid.feature_XSAVE = 'N';
		}
		
		if((ecx & 28) == 28)
		{
			cpuid.feature_OSXSAVE = 'J';	// Intel
		}
		else 
		{
			cpuid.feature_OSXSAVE = 'N';
		}
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

		if((edx & 19) == 19)
		{
			cpuid.feature_PSN = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_PSN = 'N';
		}

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

		if((edx & 22) == 22)
		{
			cpuid.feature_DS = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_DS = 'N';
		}

		if((edx & 23) == 23)
		{
			cpuid.feature_ACPI = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_ACPI = 'N';
		}

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

		if((edx & 28) == 28)
		{
			cpuid.feature_SS = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_SS = 'N';
		}

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

		if((edx & 30) == 30)
		{
			cpuid.feature_TM = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_TM = 'N';
		}

		if((edx & 31) == 31)
		{
			cpuid.feature_IA64 = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_IA64 = 'N';
		}

		if((edx & 32) == 32)
		{
			cpuid.feature_PGE = 'J';		// Intel
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}
		
		cpuid.feature_CMPL = 'N';		// AMD

		cpuid.feature_SVM = 'N';		// AMD

		cpuid.feature_EAS = 'N';		// AMD

		cpuid.feature_AMC8 = 'N';		// AMD

		cpuid.feature_ABM = 'N';		// AMD

		cpuid.feature_SSE4A = 'N';	// AMD

		cpuid.feature_MAS = 'N';		// AMD

		cpuid.feature_3DNP = 'N';		// AMD

		cpuid.feature_OSVW = 'N';		// AMD

		cpuid.feature_IBS = 'N';		// AMD

		cpuid.feature_SSE5 = 'N';		// AMD

		cpuid.feature_SKINIT = 'N';	// AMD

		cpuid.feature_WDT = 'N';		// AMD

		cpuid.feature_CMP8GB = 'N';	// AMD

		cpuid.feature_P1GB = 'N';		// AMD

		cpuid.feature_RDTSCP = 'N';	// AMD

		cpuid.feature_3DNE = 'N';		// AMD

		cpuid.feature_3DN = 'N';		// AMD
	}
	else if( ebx == 0x68747541 && edx == 0x69746e65  && ecx == 0x444d4163 )// AuthenticAMD
	{
		cpuid.vendor[0] = 'A'; cpuid.vendor[1] = 'M'; cpuid.vendor[2] = 'D'; cpuid.vendor[3] = '\0';
		cpuid.vendor_s[0] = 'A'; cpuid.vendor_s[1] = 'u'; cpuid.vendor_s[2] = 't'; cpuid.vendor_s[3] = 'h'; cpuid.vendor_s[4] = 'e'; cpuid.vendor_s[5] = 'n'; cpuid.vendor_s[6] = 't'; cpuid.vendor_s[7] = 'i'; cpuid.vendor_s[8] = 'c'; cpuid.vendor_s[9] = 'A'; cpuid.vendor_s[10] = 'M'; cpuid.vendor_s[11] = 'D'; cpuid.vendor_s[12] = '\0';

		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = 'N';
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}

		cpuid.feature_DTES64 = 'N';
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		cpuid.feature_DS_CPL = 'N';

		cpuid.feature_SMX = 'N';

		cpuid.feature_VMX = 'N';

		cpuid.feature_EST = 'N';

		cpuid.feature_TM2 = 'N';

		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';	
		}

		cpuid.feature_CNXT_ID = 'N';

		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		cpuid.feature_xTPR = 'N';

		cpuid.feature_PDCM = 'N';

		cpuid.feature_DCA = 'N';

		cpuid.feature_SSE41 = 'N';

		cpuid.feature_SSE42 = 'N';

		cpuid.feature_x2APIC = 'N';

		cpuid.feature_MOVBE = 'N';
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		cpuid.feature_XSAVE = 'N';

		cpuid.feature_OSXSAVE = 'N';
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

			cpuid.feature_PSN = 'N';		// Intel

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

			cpuid.feature_DS = 'N';		// Intel

			cpuid.feature_ACPI = 'N';		// Intel

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

			cpuid.feature_SS = 'N';		// Intel

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

			cpuid.feature_TM = 'N';		// Intel

			cpuid.feature_IA64 = 'N';		// Intel

			cpuid.feature_PGE = 'N';		// Intel
		
		cpuid_(0x80000001, max, ebx, ecx, edx);

		// ECX
		if((ecx & 2) == 2)
		{
			cpuid.feature_CMPL = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_CMPL = 'N';
		}
		
		if((ecx & 3) == 3)
		{
			cpuid.feature_SVM = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_SVM = 'N';
		}
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_EAS = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_EAS = 'N';
		}
		
		if((ecx & 5) == 5)
		{
			cpuid.feature_AMC8 = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_AMC8 = 'N';
		}
		
		if((ecx & 6) == 6)
		{
			cpuid.feature_ABM = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_ABM = 'N';
		}
		
		if((ecx & 7) == 7)
		{
			cpuid.feature_SSE4A = 'J';	// AMD
		}
		else 
		{
			cpuid.feature_SSE4A = 'N';
		}
		
		if((ecx & 8) == 8)
		{
			cpuid.feature_MAS = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_MAS = 'N';
		}
		
		if((ecx & 9) == 9)
		{
			cpuid.feature_3DNP = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_3DNP = 'N';
		}
		
		if((ecx & 10) == 10)
		{
			cpuid.feature_OSVW = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_OSVW = 'N';
		}
		
		if((ecx & 11) == 11)
		{
			cpuid.feature_IBS = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_IBS = 'N';
		}
		
		if((ecx & 12) == 12)
		{
			cpuid.feature_SSE5 = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_SSE5 = 'N';
		}
		
		if((ecx & 13) == 13)
		{
			cpuid.feature_SKINIT = 'J';	// AMD
		}
		else 
		{
			cpuid.feature_SKINIT = 'N';
		}
		
		if((ecx & 14) == 14)
		{
			cpuid.feature_WDT = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_WDT = 'N';
		}

		// EDX	
		if((ecx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}
		
		if((ecx & 1) == 1)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}
		
		if((ecx & 1) == 1)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}
		
		if((ecx & 1) == 1)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}		
		
		if((ecx & 1) == 1)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}
		
		if((ecx & 1) == 1)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}
				
		if((ecx & 1) == 1)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}
				
		if((ecx & 1) == 1)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}
				
		if((ecx & 1) == 1)
		{
			cpuid.feature_CMP8GB = 'J';	// AMD
		}
		else 
		{
			cpuid.feature_CMP8GB = 'N';
		}
				
		if((ecx & 1) == 1)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}
				
		if((ecx & 1) == 1)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((ecx & 1) == 1)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((ecx & 1) == 1)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}		

		if((ecx & 1) == 1)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}		

		if((ecx & 1) == 1)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}		

		if((ecx & 1) == 1)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}		

		if((ecx & 1) == 1)
		{
			cpuid.feature_MME = 'J';
		}
		else 
		{
			cpuid.feature_MME = 'N';
		}		
		
		if((ecx & 1) == 1)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}
		
		if((ecx & 1) == 1)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}
		
		if((ecx & 1) == 1)
		{
			cpuid.feature_FFXSR = 'J';
		}
		else 
		{
			cpuid.feature_FFXSR = 'N';
		}
		
		if((ecx & 1) == 1)
		{
			cpuid.feature_P1GB = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_P1GB = 'N';
		}
		
		if((ecx & 1) == 1)
		{
			cpuid.feature_RDTSCP = 'J';	// AMD
		}
		else 
		{
			cpuid.feature_RDTSCP = 'N';
		}
				
		if((ecx & 1) == 1)
		{
			cpuid.feature_3DNE = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_3DNE = 'N';
		}
				
		if((ecx & 1) == 1)
		{
			cpuid.feature_3DN = 'J';		// AMD
		}
		else 
		{
			cpuid.feature_3DN = 'N';
		}
	}
	else if( ebx == 0x746e6543 && edx == 0x48727561  && ecx == 0x736c7561 )// CentaurHauls
	{
		cpuid.vendor[0] = 'C'; cpuid.vendor[1] = 'e'; cpuid.vendor[2] = 'n'; cpuid.vendor[3] = 't'; cpuid.vendor[4] = 'a'; cpuid.vendor[5] = 'u'; cpuid.vendor[6] = 'r'; cpuid.vendor[7] = '\0';
		cpuid.vendor_s[0] = 'C'; cpuid.vendor_s[1] = 'e'; cpuid.vendor_s[2] = 'n'; cpuid.vendor_s[3] = 't'; cpuid.vendor_s[4] = 'a'; cpuid.vendor_s[5] = 'u'; cpuid.vendor_s[6] = 'r'; cpuid.vendor_s[7] = 'H'; cpuid.vendor_s[8] = 'a'; cpuid.vendor_s[9] = 'u'; cpuid.vendor_s[10] = 'l'; cpuid.vendor_s[11] = 's'; cpuid.vendor_s[12] = '\0';

		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = 'N';
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}

		cpuid.feature_DTES64 = 'N';
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		cpuid.feature_DS_CPL = 'N';

		cpuid.feature_SMX = 'N';

		cpuid.feature_VMX = 'N';

		cpuid.feature_EST = 'N';

		cpuid.feature_TM2 = 'N';

		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';	
		}

		cpuid.feature_CNXT_ID = 'N';

		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		cpuid.feature_xTPR = 'N';

		cpuid.feature_PDCM = 'N';

		cpuid.feature_DCA = 'N';

		cpuid.feature_SSE41 = 'N';

		cpuid.feature_SSE42 = 'N';

		cpuid.feature_x2APIC = 'N';

		cpuid.feature_MOVBE = 'N';
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		cpuid.feature_XSAVE = 'N';

		cpuid.feature_OSXSAVE = 'N';
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

			cpuid.feature_PSN = 'N';		// Intel

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

			cpuid.feature_DS = 'N';		// Intel

			cpuid.feature_ACPI = 'N';		// Intel

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

			cpuid.feature_SS = 'N';		// Intel

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

			cpuid.feature_TM = 'N';		// Intel

			cpuid.feature_IA64 = 'N';		// Intel

			cpuid.feature_PGE = 'N';		// Intel
					
		cpuid.feature_CMPL = 'N';		// AMD

		cpuid.feature_SVM = 'N';		// AMD

		cpuid.feature_EAS = 'N';		// AMD

		cpuid.feature_AMC8 = 'N';		// AMD

		cpuid.feature_ABM = 'N';		// AMD

		cpuid.feature_SSE4A = 'N';	// AMD

		cpuid.feature_MAS = 'N';		// AMD

		cpuid.feature_3DNP = 'N';		// AMD

		cpuid.feature_OSVW = 'N';		// AMD

		cpuid.feature_IBS = 'N';		// AMD

		cpuid.feature_SSE5 = 'N';		// AMD

		cpuid.feature_SKINIT = 'N';	// AMD

		cpuid.feature_WDT = 'N';		// AMD

		cpuid.feature_CMP8GB = 'N';	// AMD

		cpuid.feature_P1GB = 'N';		// AMD

		cpuid.feature_RDTSCP = 'N';	// AMD

		cpuid.feature_3DNE = 'N';		// AMD

		cpuid.feature_3DN = 'N';		// AMD
	}
	else if( ebx == 0x69727943 && edx == 0x736e4978  && ecx == 0x64616574 )// CyrixInstead
	{
		cpuid.vendor[0] = 'C'; cpuid.vendor[1] = 'y'; cpuid.vendor[2] = 'r'; cpuid.vendor[3] = 'i'; cpuid.vendor[4] = 'x'; cpuid.vendor[5] = '\0'; 
		cpuid.vendor_s[0] = 'C'; cpuid.vendor_s[1] = 'y'; cpuid.vendor_s[2] = 'r'; cpuid.vendor_s[3] = 'i'; cpuid.vendor_s[4] = 'x'; cpuid.vendor_s[5] = 'I'; cpuid.vendor_s[6] = 'n'; cpuid.vendor_s[7] = 's'; cpuid.vendor_s[8] = 't'; cpuid.vendor_s[9] = 'e'; cpuid.vendor_s[10] = 'a'; cpuid.vendor_s[11] = 'd'; cpuid.vendor_s[12] = '\0';

		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = 'N';
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}

		cpuid.feature_DTES64 = 'N';
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		cpuid.feature_DS_CPL = 'N';

		cpuid.feature_SMX = 'N';

		cpuid.feature_VMX = 'N';

		cpuid.feature_EST = 'N';

		cpuid.feature_TM2 = 'N';

		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';	
		}

		cpuid.feature_CNXT_ID = 'N';

		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		cpuid.feature_xTPR = 'N';

		cpuid.feature_PDCM = 'N';

		cpuid.feature_DCA = 'N';

		cpuid.feature_SSE41 = 'N';

		cpuid.feature_SSE42 = 'N';

		cpuid.feature_x2APIC = 'N';

		cpuid.feature_MOVBE = 'N';
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		cpuid.feature_XSAVE = 'N';

		cpuid.feature_OSXSAVE = 'N';
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

			cpuid.feature_PSN = 'N';		// Intel

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

			cpuid.feature_DS = 'N';		// Intel

			cpuid.feature_ACPI = 'N';		// Intel

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

			cpuid.feature_SS = 'N';		// Intel

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

			cpuid.feature_TM = 'N';		// Intel

			cpuid.feature_IA64 = 'N';		// Intel

			cpuid.feature_PGE = 'N';		// Intel
					
		cpuid.feature_CMPL = 'N';		// AMD

		cpuid.feature_SVM = 'N';		// AMD

		cpuid.feature_EAS = 'N';		// AMD

		cpuid.feature_AMC8 = 'N';		// AMD

		cpuid.feature_ABM = 'N';		// AMD

		cpuid.feature_SSE4A = 'N';	// AMD

		cpuid.feature_MAS = 'N';		// AMD

		cpuid.feature_3DNP = 'N';		// AMD

		cpuid.feature_OSVW = 'N';		// AMD

		cpuid.feature_IBS = 'N';		// AMD

		cpuid.feature_SSE5 = 'N';		// AMD

		cpuid.feature_SKINIT = 'N';	// AMD

		cpuid.feature_WDT = 'N';		// AMD

		cpuid.feature_CMP8GB = 'N';	// AMD

		cpuid.feature_P1GB = 'N';		// AMD

		cpuid.feature_RDTSCP = 'N';	// AMD

		cpuid.feature_3DNE = 'N';		// AMD

		cpuid.feature_3DN = 'N';		// AMD
	}
	else if( ebx == 0x4778654e && edx == 0x72446e65  && ecx == 0x6e657669 )// NexGenDriven
	{
		cpuid.vendor[0] = 'N'; cpuid.vendor[1] = 'e'; cpuid.vendor[2] = 'x'; cpuid.vendor[3] = 'G'; cpuid.vendor[4] = 'e'; cpuid.vendor[5] = 'n'; cpuid.vendor[6] = '\0';
		cpuid.vendor_s[0] = 'N'; cpuid.vendor_s[1] = 'e'; cpuid.vendor_s[2] = 'x'; cpuid.vendor_s[3] = 'G'; cpuid.vendor_s[4] = 'e'; cpuid.vendor_s[5] = 'n'; cpuid.vendor_s[6] = 'D'; cpuid.vendor_s[7] = 'r'; cpuid.vendor_s[8] = 'i'; cpuid.vendor_s[9] = 'v'; cpuid.vendor_s[10] = 'e'; cpuid.vendor_s[11] = 'n'; cpuid.vendor_s[12] = '\0';

		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = 'N';
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}

		cpuid.feature_DTES64 = 'N';
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		cpuid.feature_DS_CPL = 'N';

		cpuid.feature_SMX = 'N';

		cpuid.feature_VMX = 'N';

		cpuid.feature_EST = 'N';

		cpuid.feature_TM2 = 'N';

		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';	
		}

		cpuid.feature_CNXT_ID = 'N';

		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		cpuid.feature_xTPR = 'N';

		cpuid.feature_PDCM = 'N';

		cpuid.feature_DCA = 'N';

		cpuid.feature_SSE41 = 'N';

		cpuid.feature_SSE42 = 'N';

		cpuid.feature_x2APIC = 'N';

		cpuid.feature_MOVBE = 'N';
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		cpuid.feature_XSAVE = 'N';

		cpuid.feature_OSXSAVE = 'N';
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

			cpuid.feature_PSN = 'N';		// Intel

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

			cpuid.feature_DS = 'N';		// Intel

			cpuid.feature_ACPI = 'N';		// Intel

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

			cpuid.feature_SS = 'N';		// Intel

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

			cpuid.feature_TM = 'N';		// Intel

			cpuid.feature_IA64 = 'N';		// Intel

			cpuid.feature_PGE = 'N';		// Intel
					
		cpuid.feature_CMPL = 'N';		// AMD

		cpuid.feature_SVM = 'N';		// AMD

		cpuid.feature_EAS = 'N';		// AMD

		cpuid.feature_AMC8 = 'N';		// AMD

		cpuid.feature_ABM = 'N';		// AMD

		cpuid.feature_SSE4A = 'N';	// AMD

		cpuid.feature_MAS = 'N';		// AMD

		cpuid.feature_3DNP = 'N';		// AMD

		cpuid.feature_OSVW = 'N';		// AMD

		cpuid.feature_IBS = 'N';		// AMD

		cpuid.feature_SSE5 = 'N';		// AMD

		cpuid.feature_SKINIT = 'N';	// AMD

		cpuid.feature_WDT = 'N';		// AMD

		cpuid.feature_CMP8GB = 'N';	// AMD

		cpuid.feature_P1GB = 'N';		// AMD

		cpuid.feature_RDTSCP = 'N';	// AMD

		cpuid.feature_3DNE = 'N';		// AMD

		cpuid.feature_3DN = 'N';		// AMD
	}
	else if( ebx == 0x646f6547 && edx == 0x79622065  && ecx == 0x43534e20 )// Geode by NSC
	{
		cpuid.vendor[0] = 'N'; cpuid.vendor[1] = 'a'; cpuid.vendor[2] = 't'; cpuid.vendor[3] = 'i'; cpuid.vendor[4] = 'o'; cpuid.vendor[5] = 'n'; cpuid.vendor[6] = 'a'; cpuid.vendor[7] = 'l'; cpuid.vendor[8] = ' '; cpuid.vendor[9] = 'S'; cpuid.vendor[10] = 'e'; cpuid.vendor[11] = 'm'; cpuid.vendor[12] = 'i'; cpuid.vendor[13] = 'c'; cpuid.vendor[14] = 'o'; cpuid.vendor[15] = 'n'; cpuid.vendor[16] = 'd'; cpuid.vendor[17] = 'u'; cpuid.vendor[18] = 'c'; cpuid.vendor[19] = 't'; cpuid.vendor[20] = 'o'; cpuid.vendor[21] = 'r'; cpuid.vendor[22] = '\0';
		cpuid.vendor_s[0] = 'G'; cpuid.vendor_s[1] = 'e'; cpuid.vendor_s[2] = 'o'; cpuid.vendor_s[3] = 'd'; cpuid.vendor_s[4] = 'e'; cpuid.vendor_s[5] = ' '; cpuid.vendor_s[6] = 'b'; cpuid.vendor_s[7] = 'y'; cpuid.vendor_s[8] = ' '; cpuid.vendor_s[9] = 'N'; cpuid.vendor_s[10] = 'S'; cpuid.vendor_s[11] = 'C'; cpuid.vendor_s[12] = '\0';

		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = 'N';
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}

		cpuid.feature_DTES64 = 'N';
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		cpuid.feature_DS_CPL = 'N';

		cpuid.feature_SMX = 'N';

		cpuid.feature_VMX = 'N';

		cpuid.feature_EST = 'N';

		cpuid.feature_TM2 = 'N';

		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';	
		}

		cpuid.feature_CNXT_ID = 'N';

		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		cpuid.feature_xTPR = 'N';

		cpuid.feature_PDCM = 'N';

		cpuid.feature_DCA = 'N';

		cpuid.feature_SSE41 = 'N';

		cpuid.feature_SSE42 = 'N';

		cpuid.feature_x2APIC = 'N';

		cpuid.feature_MOVBE = 'N';
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		cpuid.feature_XSAVE = 'N';

		cpuid.feature_OSXSAVE = 'N';
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

			cpuid.feature_PSN = 'N';		// Intel

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

			cpuid.feature_DS = 'N';		// Intel

			cpuid.feature_ACPI = 'N';		// Intel

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

			cpuid.feature_SS = 'N';		// Intel

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

			cpuid.feature_TM = 'N';		// Intel

			cpuid.feature_IA64 = 'N';		// Intel

			cpuid.feature_PGE = 'N';		// Intel
					
		cpuid.feature_CMPL = 'N';		// AMD

		cpuid.feature_SVM = 'N';		// AMD

		cpuid.feature_EAS = 'N';		// AMD

		cpuid.feature_AMC8 = 'N';		// AMD

		cpuid.feature_ABM = 'N';		// AMD

		cpuid.feature_SSE4A = 'N';	// AMD

		cpuid.feature_MAS = 'N';		// AMD

		cpuid.feature_3DNP = 'N';		// AMD

		cpuid.feature_OSVW = 'N';		// AMD

		cpuid.feature_IBS = 'N';		// AMD

		cpuid.feature_SSE5 = 'N';		// AMD

		cpuid.feature_SKINIT = 'N';	// AMD

		cpuid.feature_WDT = 'N';		// AMD

		cpuid.feature_CMP8GB = 'N';	// AMD

		cpuid.feature_P1GB = 'N';		// AMD

		cpuid.feature_RDTSCP = 'N';	// AMD

		cpuid.feature_3DNE = 'N';		// AMD

		cpuid.feature_3DN = 'N';		// AMD
	}
	else if( ebx == 0x65736952 && edx == 0x65736952  && ecx == 0x65736952 )// RiseRiseRise
	{
		cpuid.vendor[0] = 'R'; cpuid.vendor[1] = 'i'; cpuid.vendor[2] = 's'; cpuid.vendor[3] = 'e'; cpuid.vendor[4] = '\0';
		cpuid.vendor_s[0] = 'R'; cpuid.vendor_s[1] = 'i'; cpuid.vendor_s[2] = 's'; cpuid.vendor_s[3] = 'e'; cpuid.vendor_s[4] = 'R'; cpuid.vendor_s[5] = 'i'; cpuid.vendor_s[6] = 's'; cpuid.vendor_s[7] = 'e'; cpuid.vendor_s[8] = 'R'; cpuid.vendor_s[9] = 'i'; cpuid.vendor_s[10] = 's'; cpuid.vendor_s[11] = 'e'; cpuid.vendor_s[12] = '\0';

		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = 'N';
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}

		cpuid.feature_DTES64 = 'N';
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		cpuid.feature_DS_CPL = 'N';

		cpuid.feature_SMX = 'N';

		cpuid.feature_VMX = 'N';

		cpuid.feature_EST = 'N';

		cpuid.feature_TM2 = 'N';

		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';	
		}

		cpuid.feature_CNXT_ID = 'N';

		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		cpuid.feature_xTPR = 'N';

		cpuid.feature_PDCM = 'N';

		cpuid.feature_DCA = 'N';

		cpuid.feature_SSE41 = 'N';

		cpuid.feature_SSE42 = 'N';

		cpuid.feature_x2APIC = 'N';

		cpuid.feature_MOVBE = 'N';
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		cpuid.feature_XSAVE = 'N';

		cpuid.feature_OSXSAVE = 'N';
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

			cpuid.feature_PSN = 'N';		// Intel

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

			cpuid.feature_DS = 'N';		// Intel

			cpuid.feature_ACPI = 'N';		// Intel

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

			cpuid.feature_SS = 'N';		// Intel

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

			cpuid.feature_TM = 'N';		// Intel

			cpuid.feature_IA64 = 'N';		// Intel

			cpuid.feature_PGE = 'N';		// Intel
					
		cpuid.feature_CMPL = 'N';		// AMD

		cpuid.feature_SVM = 'N';		// AMD

		cpuid.feature_EAS = 'N';		// AMD

		cpuid.feature_AMC8 = 'N';		// AMD

		cpuid.feature_ABM = 'N';		// AMD

		cpuid.feature_SSE4A = 'N';	// AMD

		cpuid.feature_MAS = 'N';		// AMD

		cpuid.feature_3DNP = 'N';		// AMD

		cpuid.feature_OSVW = 'N';		// AMD

		cpuid.feature_IBS = 'N';		// AMD

		cpuid.feature_SSE5 = 'N';		// AMD

		cpuid.feature_SKINIT = 'N';	// AMD

		cpuid.feature_WDT = 'N';		// AMD

		cpuid.feature_CMP8GB = 'N';	// AMD

		cpuid.feature_P1GB = 'N';		// AMD

		cpuid.feature_RDTSCP = 'N';	// AMD

		cpuid.feature_3DNE = 'N';		// AMD

		cpuid.feature_3DN = 'N';		// AMD
	}
	else if( ebx == 0x20536953 && edx == 0x20536953  && ecx == 0x20536953 )// SiS SiS SiS 
	{
		cpuid.vendor[0] = 'S'; cpuid.vendor[1] = 'i'; cpuid.vendor[2] = 'S'; cpuid.vendor[3] = '\0';
		cpuid.vendor_s[0] = 'S'; cpuid.vendor_s[1] = 'i'; cpuid.vendor_s[2] = 'S'; cpuid.vendor_s[3] = ' '; cpuid.vendor_s[4] = 'S'; cpuid.vendor_s[5] = 'i'; cpuid.vendor_s[6] = 'S'; cpuid.vendor_s[7] = ' '; cpuid.vendor_s[8] = 'S'; cpuid.vendor_s[9] = 'i'; cpuid.vendor_s[10] = 'S'; cpuid.vendor_s[11] = ' '; cpuid.vendor_s[12] = '\0';

		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = 'N';
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}

		cpuid.feature_DTES64 = 'N';
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		cpuid.feature_DS_CPL = 'N';

		cpuid.feature_SMX = 'N';

		cpuid.feature_VMX = 'N';

		cpuid.feature_EST = 'N';

		cpuid.feature_TM2 = 'N';

		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';	
		}

		cpuid.feature_CNXT_ID = 'N';

		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		cpuid.feature_xTPR = 'N';

		cpuid.feature_PDCM = 'N';

		cpuid.feature_DCA = 'N';

		cpuid.feature_SSE41 = 'N';

		cpuid.feature_SSE42 = 'N';

		cpuid.feature_x2APIC = 'N';

		cpuid.feature_MOVBE = 'N';
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		cpuid.feature_XSAVE = 'N';

		cpuid.feature_OSXSAVE = 'N';
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

			cpuid.feature_PSN = 'N';		// Intel

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

			cpuid.feature_DS = 'N';		// Intel

			cpuid.feature_ACPI = 'N';		// Intel

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

			cpuid.feature_SS = 'N';		// Intel

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

			cpuid.feature_TM = 'N';		// Intel

			cpuid.feature_IA64 = 'N';		// Intel

			cpuid.feature_PGE = 'N';		// Intel
					
		cpuid.feature_CMPL = 'N';		// AMD

		cpuid.feature_SVM = 'N';		// AMD

		cpuid.feature_EAS = 'N';		// AMD

		cpuid.feature_AMC8 = 'N';		// AMD

		cpuid.feature_ABM = 'N';		// AMD

		cpuid.feature_SSE4A = 'N';	// AMD

		cpuid.feature_MAS = 'N';		// AMD

		cpuid.feature_3DNP = 'N';		// AMD

		cpuid.feature_OSVW = 'N';		// AMD

		cpuid.feature_IBS = 'N';		// AMD

		cpuid.feature_SSE5 = 'N';		// AMD

		cpuid.feature_SKINIT = 'N';	// AMD

		cpuid.feature_WDT = 'N';		// AMD

		cpuid.feature_CMP8GB = 'N';	// AMD

		cpuid.feature_P1GB = 'N';		// AMD

		cpuid.feature_RDTSCP = 'N';	// AMD

		cpuid.feature_3DNE = 'N';		// AMD

		cpuid.feature_3DN = 'N';		// AMD
	}
	else if( ebx == 0x756e6547 && edx == 0x54656e69  && ecx == 0x3638784d )// GenuineTMx86
	{
		cpuid.vendor[0] = 'T'; cpuid.vendor[1] = 'r'; cpuid.vendor[2] = 'a'; cpuid.vendor[3] = 'n'; cpuid.vendor[4] = 's'; cpuid.vendor[5] = 'm'; cpuid.vendor[6] = 'e'; cpuid.vendor[7] = 't'; cpuid.vendor[8] = 'a'; cpuid.vendor[9] = '\0';
		cpuid.vendor_s[0] = 'G'; cpuid.vendor_s[1] = 'e'; cpuid.vendor_s[2] = 'n'; cpuid.vendor_s[3] = 'u'; cpuid.vendor_s[4] = 'i'; cpuid.vendor_s[5] = 'n'; cpuid.vendor_s[6] = 'e'; cpuid.vendor_s[7] = 'T'; cpuid.vendor_s[8] = 'M'; cpuid.vendor_s[9] = 'x'; cpuid.vendor_s[10] = '8'; cpuid.vendor_s[11] = '6'; cpuid.vendor_s[12] = '\0';

		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = 'N';
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}

		cpuid.feature_DTES64 = 'N';
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		cpuid.feature_DS_CPL = 'N';

		cpuid.feature_SMX = 'N';

		cpuid.feature_VMX = 'N';

		cpuid.feature_EST = 'N';

		cpuid.feature_TM2 = 'N';

		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';	
		}

		cpuid.feature_CNXT_ID = 'N';

		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		cpuid.feature_xTPR = 'N';

		cpuid.feature_PDCM = 'N';

		cpuid.feature_DCA = 'N';

		cpuid.feature_SSE41 = 'N';

		cpuid.feature_SSE42 = 'N';

		cpuid.feature_x2APIC = 'N';

		cpuid.feature_MOVBE = 'N';
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		cpuid.feature_XSAVE = 'N';

		cpuid.feature_OSXSAVE = 'N';
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

			cpuid.feature_PSN = 'N';		// Intel

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

			cpuid.feature_DS = 'N';		// Intel

			cpuid.feature_ACPI = 'N';		// Intel

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

			cpuid.feature_SS = 'N';		// Intel

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

			cpuid.feature_TM = 'N';		// Intel

			cpuid.feature_IA64 = 'N';		// Intel

			cpuid.feature_PGE = 'N';		// Intel
					
		cpuid.feature_CMPL = 'N';		// AMD

		cpuid.feature_SVM = 'N';		// AMD

		cpuid.feature_EAS = 'N';		// AMD

		cpuid.feature_AMC8 = 'N';		// AMD

		cpuid.feature_ABM = 'N';		// AMD

		cpuid.feature_SSE4A = 'N';	// AMD

		cpuid.feature_MAS = 'N';		// AMD

		cpuid.feature_3DNP = 'N';		// AMD

		cpuid.feature_OSVW = 'N';		// AMD

		cpuid.feature_IBS = 'N';		// AMD

		cpuid.feature_SSE5 = 'N';		// AMD

		cpuid.feature_SKINIT = 'N';	// AMD

		cpuid.feature_WDT = 'N';		// AMD

		cpuid.feature_CMP8GB = 'N';	// AMD

		cpuid.feature_P1GB = 'N';		// AMD

		cpuid.feature_RDTSCP = 'N';	// AMD

		cpuid.feature_3DNE = 'N';		// AMD

		cpuid.feature_3DN = 'N';		// AMD
	}
	else if( ebx == 0x20434d55 && edx == 0x20434d55  && ecx == 0x20434d55 )// UMC UMC UMC 
	{
		cpuid.vendor[0] = 'U'; cpuid.vendor[1] = 'M'; cpuid.vendor[2] = 'C'; cpuid.vendor[3] = '\0';
		cpuid.vendor_s[0] = 'U'; cpuid.vendor_s[1] = 'M'; cpuid.vendor_s[2] = 'C'; cpuid.vendor_s[3] = ' '; cpuid.vendor_s[4] = 'U'; cpuid.vendor_s[5] = 'M'; cpuid.vendor_s[6] = 'C'; cpuid.vendor_s[7] = ' '; cpuid.vendor_s[8] = 'U'; cpuid.vendor_s[9] = 'M'; cpuid.vendor_s[10] = 'C'; cpuid.vendor_s[11] = ' '; cpuid.vendor_s[12] = '\0';

		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = 'N';
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}

		cpuid.feature_DTES64 = 'N';
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		cpuid.feature_DS_CPL = 'N';

		cpuid.feature_SMX = 'N';

		cpuid.feature_VMX = 'N';

		cpuid.feature_EST = 'N';

		cpuid.feature_TM2 = 'N';

		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';	
		}

		cpuid.feature_CNXT_ID = 'N';

		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		cpuid.feature_xTPR = 'N';

		cpuid.feature_PDCM = 'N';

		cpuid.feature_DCA = 'N';

		cpuid.feature_SSE41 = 'N';

		cpuid.feature_SSE42 = 'N';

		cpuid.feature_x2APIC = 'N';

		cpuid.feature_MOVBE = 'N';
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		cpuid.feature_XSAVE = 'N';

		cpuid.feature_OSXSAVE = 'N';
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

			cpuid.feature_PSN = 'N';		// Intel

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

			cpuid.feature_DS = 'N';		// Intel

			cpuid.feature_ACPI = 'N';		// Intel

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

			cpuid.feature_SS = 'N';		// Intel

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

			cpuid.feature_TM = 'N';		// Intel

			cpuid.feature_IA64 = 'N';		// Intel

			cpuid.feature_PGE = 'N';		// Intel
					
		cpuid.feature_CMPL = 'N';		// AMD

		cpuid.feature_SVM = 'N';		// AMD

		cpuid.feature_EAS = 'N';		// AMD

		cpuid.feature_AMC8 = 'N';		// AMD

		cpuid.feature_ABM = 'N';		// AMD

		cpuid.feature_SSE4A = 'N';	// AMD

		cpuid.feature_MAS = 'N';		// AMD

		cpuid.feature_3DNP = 'N';		// AMD

		cpuid.feature_OSVW = 'N';		// AMD

		cpuid.feature_IBS = 'N';		// AMD

		cpuid.feature_SSE5 = 'N';		// AMD

		cpuid.feature_SKINIT = 'N';	// AMD

		cpuid.feature_WDT = 'N';		// AMD

		cpuid.feature_CMP8GB = 'N';	// AMD

		cpuid.feature_P1GB = 'N';		// AMD

		cpuid.feature_RDTSCP = 'N';	// AMD

		cpuid.feature_3DNE = 'N';		// AMD

		cpuid.feature_3DN = 'N';		// AMD
	}
	else if( ebx == 0x20414956 && edx == 0x20414956  && ecx == 0x20414956 )// VIA VIA VIA 
	{
		cpuid.vendor[0] = 'V'; cpuid.vendor[1] = 'I'; cpuid.vendor[2] = 'A'; cpuid.vendor[3] = '\0';
		cpuid.vendor_s[0] = 'V'; cpuid.vendor_s[1] = 'I'; cpuid.vendor_s[2] = 'A'; cpuid.vendor_s[3] = ' '; cpuid.vendor_s[4] = 'V'; cpuid.vendor_s[5] = 'I'; cpuid.vendor_s[6] = 'A'; cpuid.vendor_s[7] = ' '; cpuid.vendor_s[8] = 'V'; cpuid.vendor_s[9] = 'I'; cpuid.vendor_s[10] = 'A'; cpuid.vendor_s[11] = ' '; cpuid.vendor_s[12] = '\0';

		cpuid_(0x00000001, eax, ebx, ecx, edx);

		// EAX
		cpuid.stepping = (eax & 0x0000000f);
		cpuid.modell = (eax & 0x000000f0) >> 4;
		cpuid.familie = (eax & 0x00000f00) >> 8;
		cpuid.typ = 'N';
		cpuid.e_modell = (eax & 0x000f0000) >> 16;
		cpuid.e_familie = (eax & 0x0ff00000) >> 20;

		// EBX
		cpuid.brand = (ebx & 0x000000ff) >> 0;
		cpuid.cf_size = (ebx & 0x0000ff00) >> 8;
		cpuid.anz_proz = (ebx & 0x00ff0000) >> 16;
		cpuid.apic_id = (ebx & 0xff000000) >> 24;

		// ECX
		if((ecx & 1) == 1)
		{
			cpuid.feature_SSE3 = 'J';
		}
		else 
		{
			cpuid.feature_SSE3 = 'N';
		}

		cpuid.feature_DTES64 = 'N';
		
		if((ecx & 4) == 4)
		{
			cpuid.feature_MONITOR = 'J';
		}
		else 
		{
			cpuid.feature_MONITOR = 'N';
		}
		
		cpuid.feature_DS_CPL = 'N';

		cpuid.feature_SMX = 'N';

		cpuid.feature_VMX = 'N';

		cpuid.feature_EST = 'N';

		cpuid.feature_TM2 = 'N';

		if((ecx & 10) == 10)
		{
			cpuid.feature_SSSE3 = 'J';		
		}
		else 
		{
			cpuid.feature_SSSE3 = 'N';	
		}

		cpuid.feature_CNXT_ID = 'N';

		if((ecx & 14) == 14)
		{
			cpuid.feature_CX16 = 'J';		
		}
		else 
		{
			cpuid.feature_CX16 = 'N';
		}
		
		cpuid.feature_xTPR = 'N';

		cpuid.feature_PDCM = 'N';

		cpuid.feature_DCA = 'N';

		cpuid.feature_SSE41 = 'N';

		cpuid.feature_SSE42 = 'N';

		cpuid.feature_x2APIC = 'N';

		cpuid.feature_MOVBE = 'N';
		
		if((ecx & 24) == 24)
		{
			cpuid.feature_POPCNT = 'J';	
		}
		else 
		{
			cpuid.feature_POPCNT = 'N';
		}
		
		cpuid.feature_XSAVE = 'N';

		cpuid.feature_OSXSAVE = 'N';
		
		//EDX
		if((edx & 1) == 1)
		{
			cpuid.feature_FPU = 'J';
		}
		else 
		{
			cpuid.feature_FPU = 'N';
		}

		if((edx & 2) == 2)
		{
			cpuid.feature_VME = 'J';
		}
		else 
		{
			cpuid.feature_VME = 'N';
		}

		if((edx & 3) == 3)
		{
			cpuid.feature_DE = 'J';
		}
		else 
		{
			cpuid.feature_DE = 'N';
		}

		if((edx & 4) == 4)
		{
			cpuid.feature_PSE = 'J';
		}
		else 
		{
			cpuid.feature_PSE = 'N';
		}

		if((edx & 5) == 5)
		{
			cpuid.feature_TSC = 'J';
		}
		else 
		{
			cpuid.feature_TSC = 'N';
		}

		if((edx & 6) == 6)
		{
			cpuid.feature_MSR = 'J';
		}
		else 
		{
			cpuid.feature_MSR = 'N';
		}

		if((edx & 7) == 7)
		{
			cpuid.feature_PAE = 'J';
		}
		else 
		{
			cpuid.feature_PAE = 'N';
		}

		if((edx & 8) == 8)
		{
			cpuid.feature_MCE = 'J';
		}
		else 
		{
			cpuid.feature_MCE = 'N';
		}

		if((edx & 9) == 9)
		{
			cpuid.feature_CX8 = 'J';
		}
		else 
		{
			cpuid.feature_CX8 = 'N';
		}

		if((edx & 10) == 10)
		{
			cpuid.feature_APIC = 'J';
		}
		else 
		{
			cpuid.feature_APIC = 'N';
		}

		if((edx & 12) == 12)
		{
			cpuid.feature_SEP = 'J';
		}
		else 
		{
			cpuid.feature_SEP = 'N';
		}

		if((edx & 13) == 13)
		{
			cpuid.feature_MTRR = 'J';
		}
		else 
		{
			cpuid.feature_MTRR = 'N';
		}

		if((edx & 14) == 14)
		{
			cpuid.feature_PGE = 'J';
		}
		else 
		{
			cpuid.feature_PGE = 'N';
		}

		if((edx & 15) == 15)
		{
			cpuid.feature_MCA = 'J';
		}
		else 
		{
			cpuid.feature_MCA = 'N';
		}

		if((edx & 16) == 16)
		{
			cpuid.feature_CMOV = 'J';
		}
		else 
		{
			cpuid.feature_CMOV = 'N';
		}

		if((edx & 17) == 17)
		{
			cpuid.feature_PAT = 'J';
		}
		else 
		{
			cpuid.feature_PAT = 'N';
		}

		if((edx & 18) == 18)
		{
			cpuid.feature_PSE36 = 'J';
		}
		else 
		{
			cpuid.feature_PSE36 = 'N';
		}

			cpuid.feature_PSN = 'N';		// Intel

		if((edx & 20) == 20)
		{
			cpuid.feature_CLFLSH = 'J';
		}
		else 
		{
			cpuid.feature_CLFLSH = 'N';
		}

			cpuid.feature_DS = 'N';		// Intel

			cpuid.feature_ACPI = 'N';		// Intel

		if((edx & 24) == 24)
		{
			cpuid.feature_MMX = 'J';
		}
		else 
		{
			cpuid.feature_MMX = 'N';
		}

		if((edx & 25) == 25)
		{
			cpuid.feature_FXSR = 'J';
		}
		else 
		{
			cpuid.feature_FXSR = 'N';
		}

		if((edx & 26) == 26)
		{
			cpuid.feature_SSE = 'J';
		}
		else 
		{
			cpuid.feature_SSE = 'N';
		}

		if((edx & 27) == 27)
		{
			cpuid.feature_SSE2 = 'J';
		}
		else 
		{
			cpuid.feature_SSE2 = 'N';
		}

			cpuid.feature_SS = 'N';		// Intel

		if((edx & 29) == 29)
		{
			cpuid.feature_HTT = 'J';
		}
		else 
		{
			cpuid.feature_HTT = 'N';
		}

			cpuid.feature_TM = 'N';		// Intel

			cpuid.feature_IA64 = 'N';		// Intel

			cpuid.feature_PGE = 'N';		// Intel
					
		cpuid.feature_CMPL = 'N';		// AMD

		cpuid.feature_SVM = 'N';		// AMD

		cpuid.feature_EAS = 'N';		// AMD

		cpuid.feature_AMC8 = 'N';		// AMD

		cpuid.feature_ABM = 'N';		// AMD

		cpuid.feature_SSE4A = 'N';	// AMD

		cpuid.feature_MAS = 'N';		// AMD

		cpuid.feature_3DNP = 'N';		// AMD

		cpuid.feature_OSVW = 'N';		// AMD

		cpuid.feature_IBS = 'N';		// AMD

		cpuid.feature_SSE5 = 'N';		// AMD

		cpuid.feature_SKINIT = 'N';	// AMD

		cpuid.feature_WDT = 'N';		// AMD

		cpuid.feature_CMP8GB = 'N';	// AMD

		cpuid.feature_P1GB = 'N';		// AMD

		cpuid.feature_RDTSCP = 'N';	// AMD

		cpuid.feature_3DNE = 'N';		// AMD

		cpuid.feature_3DN = 'N';		// AMD
	}

	if(cpuid.feature_FPU == 1)
	{
		unsigned int cr4; // backup of CR4
		uint16_t cw = 0x37F;
		// place CR4 into our variable
		asm __volatile__("mov %%cr4, %0;" : "=r" (cr4));

		// set the OSFXSR bit   
		cr4 |= 0x200;

		// reload CR4 and INIT the FPU (FINIT)
		asm __volatile__("mov %0, %%cr4; finit;" : : "r"(cr4));

		// set the FPU Control Word
		asm volatile("fldcw %0;"::"m"(cw));
	}
	
}



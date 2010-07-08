#include "stdint.h"
#include "com.h"
#include "console.h"

void dis_init(void);
void dis_debug(void);

struct cpuid_t{
char vendor[23];
char vendor_s[13];
char stepping; 
char familie; 
char modell; 
char e_modell; 
char e_familie; 
char typ; 				// Intel
char brand; 
char anz_proz; 
char apic_id; 
char cf_size; 
char feature_SSE3;
char feature_DTES64;	// Intel
char feature_MONITOR;
char feature_DS_CPL;	// Intel
char feature_SMX;		// Intel
char feature_VMX;		// Intel
char feature_EST;		// Intel
char feature_TM2;		// Intel
char feature_SSSE3;		
char feature_CNXT_ID;	// Intel
char feature_CX16;		
char feature_xTPR;		// Intel
char feature_PDCM;		// Intel
char feature_DCA;		// Intel
char feature_SSE41;		// Intel
char feature_SSE42;		// Intel
char feature_x2APIC;	// Intel
char feature_MOVBE;		// Intel
char feature_POPCNT;	
char feature_XSAVE;		// Intel
char feature_OSXSAVE;	// Intel
char feature_FPU;
char feature_VME;
char feature_DE;
char feature_PSE;
char feature_TSC;
char feature_MSR;
char feature_PAE;
char feature_MCE;
char feature_CX8;
char feature_APIC;
char feature_SEP;
char feature_MTRR;
char feature_PGE;
char feature_MCA;
char feature_CMOV;
char feature_PAT;
char feature_PSE36;
char feature_PSN;		// Intel
char feature_CLFLSH;
char feature_DS;		// Intel
char feature_ACPI;		// Intel
char feature_MMX;
char feature_FXSR;
char feature_FFXSR;
char feature_SSE;
char feature_SSE2;
char feature_SS;		// Intel
char feature_HTT;
char feature_TM;		// Intel
char feature_IA64;		// Intel
char feature_CMPL;		// AMD
char feature_MME;		// AMD
char feature_SVM;		// AMD
char feature_EAS;		// AMD
char feature_AMC8;		// AMD
char feature_ABM;		// AMD
char feature_SSE4A;		// AMD
char feature_MAS;		// AMD
char feature_3DNP;		// AMD
char feature_OSVW;		// AMD
char feature_IBS;		// AMD
char feature_SSE5;		// AMD
char feature_SKINIT;	// AMD
char feature_WDT;		// AMD
char feature_CMP8GB;	// AMD
char feature_P1GB;		// AMD
char feature_RDTSCP;	// AMD
char feature_3DNE;		// AMD
char feature_3DN;		// AMD
} cpuid;

struct dis_t{
unsigned short COM1;
unsigned short COM2;
unsigned short COM3;
unsigned short COM4;
} dis;

struct bda_t{
unsigned short IO_COM1;
unsigned short IO_COM2;
unsigned short IO_COM3;
unsigned short IO_COM4;
unsigned short IO_LPT1;
unsigned short IO_LPT2;
unsigned short IO_LPT3;
unsigned short EBDA_adress;
unsigned short EW;
}__attribute__((packed));
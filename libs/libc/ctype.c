const char _ctype_[1 + 256] = {
	0,
	040,040,040,040,040,040,040,040,
	040,040|010,040|010,040|010,040|010,040|010,040,040,
	040,040,040,040,040,040,040,040,
	040,040,040,040,040,040,040,040,
	010|0200,020,020,020,020,020,020,020,
	020,020,020,020,020,020,020,020,
	04,	04,	04,	04,	04,	04,	04,	04,
	04,	04,	020,020,020,020,020,020,
	020,01|0100,01|0100,01|0100,01|0100,01|0100,01|0100,01,
	01,	01,	01,	01,	01,	01,	01,	01,
	01,	01,	01,	01,	01,	01,	01,	01,
	01,	01,	01,	020,020,020,020,020,
	020,02|0100,02|0100,02|0100,02|0100,02|0100,02|0100,02,
	02,	02,	02,	02,	02,	02,	02,	02,
	02,	02,	02,	02,	02,	02,	02,	02,
	02,	02,	02,	020,020,020,020,040
};

int isalnum(int c)
{
	return((_ctype_ + 1)[c] & (01|02|04));
}

int isalpha(int c)
{
	return((_ctype_ + 1)[c] & (01|02));
}

int iscntrl(int c)
{
	return((_ctype_ + 1)[c] & 040);
}

int isdigit(int c)
{
	return((_ctype_ + 1)[c] & 04);
}

int isgraph(int c)
{
	return((_ctype_ + 1)[c] & (020|01|02|04));
}

int islower(int c)
{
	return((_ctype_ + 1)[c] & 02);
}

int isprint(int c)
{
	return((_ctype_ + 1)[c] & (020|01|02|04|0200));
}

int ispunct(int c)
{
	return((_ctype_ + 1)[c] & 020);
}

int isspace(int c)
{
	return((_ctype_ + 1)[c] & 010);
}

int isupper(int c)
{
	return((_ctype_ + 1)[c] & 01);
}

int isxdigit(int c)
{
	return((_ctype_ + 1)[c] & ((0100)|(04)));
}

int tolower(int c)
{
	return isupper(c) ? (c) - 'A' + 'a' : c;
}

int toupper(int c)
{
  return islower(c) ? c - 'a' + 'A' : c;
}
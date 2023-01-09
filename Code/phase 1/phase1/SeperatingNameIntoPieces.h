#ifndef SEPERATINGNAMEINTOPIECES_H
#define SEPERATINGNAMEINTOPIECES_H

#include "iostream"
#include "string.h"
#include "vector"
#include "stdlib.h"
#include "QString"
#include "QStringList"
#include "FileFormat.h"
using namespace std;

class SeperatingNameIntoPieces : public FileFormat
{
public:
	/**
	 * @brief SeperatingNameIntoPieces
	 * starting seperating into names and types and format
	 * @param list
	 */
	SeperatingNameIntoPieces (QStringList list) ;
	~SeperatingNameIntoPieces ();
	/**
	 * @brief DividingNAmesFromDatesAndFormat
	 * we insert mixed file format into vector of FileFormat
	 * @param list
	 */
	void DividingNAmesFromDatesAndFormat (QStringList list) ;
	/**
	 * @brief ValidatingFiles
	 * we pass it tp FileFormat valdidation function
	 * @param file
	 */
	void ValidatingFiles(vector<FileFormat> file);
	bool check = true ;
	SeperatingNameIntoPieces * array_list_name ;
	vector<FileFormat> file_format ;
private:

};

#endif // SEPERATINGNAMEINTOPIECES_H

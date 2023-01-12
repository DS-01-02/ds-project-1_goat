#include "SeperatingNameIntoPieces.h"



SeperatingNameIntoPieces ::SeperatingNameIntoPieces(QStringList list)
{
	DividingNAmesFromDatesAndFormat(list);
}

void SeperatingNameIntoPieces::ValidatingFiles(vector<FileFormat> file)
{
	FileFormat::ValiadatingFilesBasedDates(file);
}
SeperatingNameIntoPieces ::~SeperatingNameIntoPieces()
{
}

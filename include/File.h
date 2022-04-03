/*****************************************************************************
 * Name : Mike
 * Date : 03 Apr 2022
 * File : File.h
 *****************************************************************************/

#pragma once

// Includes
#include <stdbool.h>

// Function Prototypes

// Public Functions
bool File_SaveExecutableFileToDisk(const char* pNewExecutableBaseFilename, void* pExecutableFile, unsigned int uiExecutableFileSize, long lExecutableFileOffset);

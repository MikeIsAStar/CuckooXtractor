/*****************************************************************************
 * Name : Mike
 * Date : 03 Apr 2022
 * File : Image.h
 *****************************************************************************/

#pragma once

// Includes
#include <stdbool.h>
#include <stddef.h>

#include <winnt.h>

// Function Definitions

// Private Functions
__attribute__((always_inline))
static inline bool
Image_IsDOSHeaderMagicValid(PIMAGE_DOS_HEADER pImageDOSHeader)
{
	return (pImageDOSHeader->e_magic == IMAGE_DOS_SIGNATURE);
}

__attribute__((always_inline))
static inline bool
Image_IsOptionalHeaderMagicValid(PIMAGE_NT_HEADERS32 pImageNTHeader)
{
	return (pImageNTHeader->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC ||
		pImageNTHeader->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC);
}

__attribute__((always_inline))
static inline bool
Image_Is32BitExecutable(PIMAGE_NT_HEADERS32 pImageNTHeader)
{
	return (pImageNTHeader->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC);
}

__attribute__((always_inline))
static inline bool
Image_IsNTHeaderSignatureValid(PIMAGE_NT_HEADERS32 pImageNTHeader)
{
	return (pImageNTHeader->Signature == IMAGE_NT_SIGNATURE);
}

__attribute__((always_inline))
static inline size_t
Image_GetDOSHeaderSize(void)
{
	return sizeof(IMAGE_DOS_HEADER);
}

__attribute__((always_inline))
static inline size_t
Image_GetFileHeaderSize(void)
{
	return sizeof(IMAGE_FILE_HEADER);
}

__attribute__((always_inline))
static inline size_t
Image_GetOptionalHeaderMagicSize(void)
{
	return sizeof(((PIMAGE_NT_HEADERS32)NULL)->OptionalHeader.Magic);
}

__attribute__((always_inline))
static inline unsigned int
Image_GetSizeOfImage(PIMAGE_NT_HEADERS32 pImageNTHeader)
{
	if (Image_Is32BitExecutable(pImageNTHeader))
		return pImageNTHeader->OptionalHeader.SizeOfImage;
	else
		return ((PIMAGE_NT_HEADERS64)pImageNTHeader)->OptionalHeader.SizeOfImage;
}

__attribute__((always_inline))
static inline size_t
Image_GetNTHeaderSize(PIMAGE_NT_HEADERS32 pImageNTHeader)
{
	if (Image_Is32BitExecutable(pImageNTHeader))
		return sizeof(IMAGE_NT_HEADERS32);
	else
		return sizeof(IMAGE_NT_HEADERS64);
}

__attribute__((always_inline))
static inline size_t
Image_GetNTHeaderSignatureSize(void)
{
	return sizeof(((PIMAGE_NT_HEADERS32)NULL)->Signature);
}

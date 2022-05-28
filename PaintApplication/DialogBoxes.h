#pragma once
#include "CDialogEventHandler.h"
namespace DLOGS {
	HRESULT writeDataToFileUsingFSTREAM(std::string filepath, std::string data);
	HRESULT CDialogEventHandler_CreateInstance(REFIID riid, void** ppv);
	HRESULT _WriteDataToFile(HANDLE hFile, PCWSTR pszDataIn);
	HRESULT _WritePropertyToCustomFile(PCWSTR pszFileName, PCWSTR pszPropertyName, PCWSTR pszValue);
	HRESULT _WriteDataToCustomFile(PCWSTR pszFileName);
	HRESULT BasicFileOpen(std::string& filePath, bool saveFilePath = true);
	HRESULT AddItemsToCommonPlaces();
	HRESULT AddCustomControls();
	HRESULT SetDefaultValuesForProperties();
	HRESULT WritePropertiesUsingHandlers();
	HRESULT WritePropertiesWithoutUsingHandlers(std::string dataToWrite);
}
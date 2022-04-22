int n;
bool Flag;
DWORD dr = GetLogicalDrives(); // функция возвращает битовую маску

for (int x = 0; x<26; x++)
{
	n = ((dr >> x) & 1); // узнаём значение текущего бита
	if (n) // если единица - диск с номером x есть
	{
		char dl = 65 + x;
		string path = string({ dl }) + ":\\";

		cout << "Disk " << dl << endl;

		// здесь узнаём готово ли устройство
		WORD OldErrorMode;
		OldErrorMode = SetErrorMode(SEM_FAILCRITICALERRORS); // убираем показ ошибок
		bool ready = true;//DirectoryExists(path); // пытаемcя открыть корневую директорию
		SetErrorMode(OldErrorMode); // восстанавливаем старый режим показа ошибок

		if (ready)
		{

			UINT drive_type = GetDriveType(path.c_str()); // узнаём тип диска
			cout << endl << "Type disk: ";
			switch (drive_type)
			{
			case DRIVE_NO_ROOT_DIR: cout << "NO_ROOT_DIR" << endl; break;
			case DRIVE_REMOVABLE: cout << "REMOVABLE" << endl; break;
			case DRIVE_FIXED: cout << "FIXED" << endl; break;
			case DRIVE_REMOTE: cout << "REMOTE" << endl; break;
			case DRIVE_CDROM: cout << "CD-ROM" << endl; break;
			case DRIVE_RAMDISK: cout << "RAMDISK" << endl; break;
			default: cout << "Unknown type" << endl;
			}

			// если это HDD - заприашиваем информацию о нем
			if (drive_type & (DRIVE_FIXED | DRIVE_REMOVABLE))
			{
				unsigned __int64 FreeBytesAvailable;
				unsigned __int64 TotalNumberOfBytes;
				unsigned __int64 TotalNumberOfFreeBytes;
				char drive_label[30];
				char drive_fat[30];
				DWORD drive_sn;
				DWORD drive_name_size = sizeof(drive_label);

				// получаем данные о размерах
				Flag = ::GetDiskFreeSpaceEx(path.c_str(),
					(PULARGE_INTEGER)&FreeBytesAvailable,
					(PULARGE_INTEGER)&TotalNumberOfBytes,
					(PULARGE_INTEGER)&TotalNumberOfFreeBytes
				);
				if (Flag)
				{
					cout << endl;
					cout << "Free space: " << TotalNumberOfFreeBytes << endl;
					cout << "Space all: " << TotalNumberOfBytes << endl;
				}
				else
				{
					cout << "Ошибка в GetDiskFreeSpaceEx" << endl;
				}

				// получаем метку, серинийный номер и пр.
				Flag = GetVolumeInformation(path.c_str(),
					drive_label,
					sizeof(drive_label),
					&drive_sn,
					&drive_name_size,
					NULL,
					drive_fat,
					sizeof(drive_fat)
				);
				if (Flag)
				{
					cout << endl;
					cout << "Tom point: " << drive_label << endl;
					cout << "Serial number: " << drive_sn << endl;
					cout << "File system: " << drive_fat << endl;
				}
				else
				{
					cout << "Error in GetVolumeInformation" << endl;
				}
			}
		}
		else
		{
			cout << "Not ready";
		}
		cout << endl;
	}



	_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	hf = FindFirstFile("c:\\*", &FindFileData);
	if (hf != INVALID_HANDLE_VALUE) {
		do {
			SetConsoleTextAttribute(_hConsole,
				(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ?
					FOREGROUND_RED | FOREGROUND_GREEN :
					FOREGROUND_BLUE) |
					(FindFileData.dwFileAttributes & (FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_HIDDEN) ? 0 : FOREGROUND_INTENSITY));
			std::cout << FindFileData.cFileName << endl;
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
}
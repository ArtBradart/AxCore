#include "Explorer.h"

#include "MenuHandler.h"

Explorer::Explorer()
	:_Running(true)
{
	Begin();
}

Explorer::~Explorer() {}

bool Explorer::ConstructList(Menu& menu)
{
	if (_path.empty()) return GetDevices(menu);
	else return GetDirectories(menu);
}

bool Explorer::GetDevices(Menu& menu)
{
	menu._title.SetColor(0x000f);
	menu._title.SetText("Computer");

	WORD dr = GetLogicalDrives(); // функция возвращает битовую маску
	for (int x = 0; x < 26; x++)
	{
		int n = ((dr >> x) & 1); // узнаём значение текущего бита
		if (n) // если единица - диск с номером x есть
		{
			char dl = 65 + x;
			string path = string({ dl }) + ":\\";

			// здесь узнаём готово ли устройство
			//WORD OldErrorMode;
			//OldErrorMode = SetErrorMode(SEM_FAILCRITICALERRORS); // убираем показ ошибок
			//bool ready = DirectoryExists(path); // пытаемcя открыть корневую директорию
			//SetErrorMode(OldErrorMode); // восстанавливаем старый режим показа ошибок

			UINT drive_type = GetDriveType(path.c_str()); // узнаём тип диска


			// если это HDD - заприашиваем информацию о нем
			if (drive_type & (DRIVE_FIXED | DRIVE_REMOVABLE))
			{
				menu._list.Add(MenuItem([this, dl]() {
					_path.push_back(string({ dl }) + ":");
				}, path, 0x0005));
				/*
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
				*/
			}
		}
	}

	return !menu._list.empty();
}

bool Explorer::GetDirectories(Menu& menu)
{
	menu._title.SetColor(0x00f0);
	string path;
	for (const string& folder : _path)
	{
		path += folder + "\\";
	}
	menu._title.SetText(path);

	auto backAction = [this]() {
		_path.pop_back();
	};

	menu._list.Add(MenuItem(backAction, "../", StdColors::Back));

	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	hf = FindFirstFile((path + "*").c_str(), &FindFileData);

	if (hf != INVALID_HANDLE_VALUE) {
		do {
			bool type = bool(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
			bool hidden = bool(FindFileData.dwFileAttributes & (FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_HIDDEN));
			MenuItem item;
			WORD color;
			string name = FindFileData.cFileName;
			if (type) {
				color = FOREGROUND_RED | FOREGROUND_GREEN;
				item.SetText(name + "\\");
				item.SetAction([this, name]() {
					_path.push_back(name);
				});
			} else {
				color = FOREGROUND_BLUE;
				item.SetText(name);
				item.SetAction([this, name]() {
					string path;
					for (const string& folder : _path) path += folder + "\\";
					path += name;
					ShellExecute(0, "open", path.c_str(), 0, 0, SW_SHOW);
				});
			}

			if (!hidden) color |= FOREGROUND_INTENSITY;
			item.SetColor(color);
			menu._list.Add(item);
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
	return !menu._list.empty();
}

void Explorer::Begin()
{
	while (Tick());
}

bool Explorer::Tick()
{
	Menu directory;
	if (!ConstructList(directory)) return false;
	MenuHandler handler(directory);
	
	return _Running;
}

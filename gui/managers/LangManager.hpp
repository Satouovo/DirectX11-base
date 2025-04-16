#pragma once

class LangManager {
	int lang = 0;

	struct Lang {
        const char* label;
        int font;
        std::unordered_map< std::string, std::string > dict{ };
    };

	std::vector< Lang > languages;
public:
	void add_language( const char* label, int font, std::unordered_map< std::string, std::string > dict ) {
        languages.push_back( Lang{ label, font, dict } );
    }

    int& get_lang( ) {
        return lang;
    }

    const char* get_lang_name( ) {
        return languages[lang].label;
    }

    std::vector< Lang >& get_langs( ) {
        return languages;
    }

    int get_font( ) {
        return ( int )languages[lang].font;
    }
    
    ImFont* get_font( int sz ) {
        return fonts[ ( int )languages[lang].font ].get( sz );
    }

    void set_lang( int i ) {
        lang = i;
    }

	static LangManager& get( ) {
		static LangManager s;
		return s;
	}

    const char* translate( const char* str ) {
        if ( lang == 0 )
            return str;

        auto it = languages[lang].dict.find( str );
        if ( it == languages[lang].dict.end( ) ) return str;

        return it->second.c_str( );
    }

    void initialize( ) {
        add_language( "English", font, { } );
        add_language( "Russian", font, {
            { "Enable", u8"Включить" },
            { "Silent", u8"Незаметный" },
            { "Field of view", u8"Область" },
            { "Smooth", u8"Плавность" },
            { "Bones", u8"Кости" },
            { "Head", u8"Голова" },
            { "Neck", u8"Шея" },
            { "Body", u8"Тело" },
            { "Legs", u8"Ноги" },
            { "Arms", u8"Руки" },
            { "Standalone", u8"Стандалон" },
            { "Custom", u8"Кастомный" },
            { "Smart", u8"Умный" },
            { "Type", u8"Тип" },
            { "Enable##rcs", u8"Включить" },
            { "Draw FOV", u8"Рисовать область" },
            { "Enemies only", u8"Только враги" },
            { "Visible only", u8"Только видимые" },
            { "Ignore bots", u8"Игнорировать ботов" },
            { "Type the text...", u8"Введите текст..." },
            { "Recoil control system", u8"Контроль разброса" },
            { "Misc", u8"Прочее" },
            { "Triggerbot", u8"Триггербот" },
            { "Draw crosshair", u8"Рисовать прицел" },
            { "Hide shots", u8"Скрытые выстрелы" },
            { "Aim lock", u8"Аим лок" },
            { "Rainbow", u8"Радуга" },
            { "Thickness", u8"Толщина" },
            { "Space", u8"Пробел" },
            { "Search...", u8"Поиск..." },
            { "Settings", u8"Настройки" },
            { "Predict", u8"Предикт" },
            { "Draw target", u8"Рисовать цель" },
            { "Save target", u8"Сохранять цель" },
            { "Delay", u8"Задержка" },
            { "CONFIG", u8"КОНФИГ" },
            { "Name:", u8"Название" },
            { "Created:", u8"Дата создания:" },
            { "Created by:", u8"Создатель:" },
            { "Enter the name...", u8"Введите название..." },
            { "Load", u8"Загрузить" },
            { "Delete", u8"Удалить" },
            { "Loaded the config", u8"Конфиг загружен" },
            { "Removed the config", u8"Конфиг удален" },
            { "Enter the name!", u8"Введите название!" },
            { "Successfully created a config", u8"Конфиг успешно создан" },
            { "SUCCESS", u8"УСПЕХ" },
            { "ERROR", u8"ОШИБКА" },
            { "INFO", u8"ИНФОРМАЦИЯ" },

            { "AimAssistance", u8"Аимбот" },
            { "Visualization", u8"Визуализация" },
            { "Weapon", u8"Оружие" },
            { "Miscellaneous", u8"Прочее" },
            { "Configs", u8"Конфигурации" },
            { "General", u8"Основное" },
            { "Are you sure u want to enable it?", u8"Вы точно хотите включить это?" },
            { "This function is ", u8"Эта функция " },
            { "dangerous!", u8"опасная!" },
            { "YES", u8"ДА" },
            { "NO", u8"НЕТ" },
        } );
    }
};
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
            { "Enable", u8"��������" },
            { "Silent", u8"����������" },
            { "Field of view", u8"�������" },
            { "Smooth", u8"���������" },
            { "Bones", u8"�����" },
            { "Head", u8"������" },
            { "Neck", u8"���" },
            { "Body", u8"����" },
            { "Legs", u8"����" },
            { "Arms", u8"����" },
            { "Standalone", u8"���������" },
            { "Custom", u8"���������" },
            { "Smart", u8"�����" },
            { "Type", u8"���" },
            { "Enable##rcs", u8"��������" },
            { "Draw FOV", u8"�������� �������" },
            { "Enemies only", u8"������ �����" },
            { "Visible only", u8"������ �������" },
            { "Ignore bots", u8"������������ �����" },
            { "Type the text...", u8"������� �����..." },
            { "Recoil control system", u8"�������� ��������" },
            { "Misc", u8"������" },
            { "Triggerbot", u8"����������" },
            { "Draw crosshair", u8"�������� ������" },
            { "Hide shots", u8"������� ��������" },
            { "Aim lock", u8"��� ���" },
            { "Rainbow", u8"������" },
            { "Thickness", u8"�������" },
            { "Space", u8"������" },
            { "Search...", u8"�����..." },
            { "Settings", u8"���������" },
            { "Predict", u8"�������" },
            { "Draw target", u8"�������� ����" },
            { "Save target", u8"��������� ����" },
            { "Delay", u8"��������" },
            { "CONFIG", u8"������" },
            { "Name:", u8"��������" },
            { "Created:", u8"���� ��������:" },
            { "Created by:", u8"���������:" },
            { "Enter the name...", u8"������� ��������..." },
            { "Load", u8"���������" },
            { "Delete", u8"�������" },
            { "Loaded the config", u8"������ ��������" },
            { "Removed the config", u8"������ ������" },
            { "Enter the name!", u8"������� ��������!" },
            { "Successfully created a config", u8"������ ������� ������" },
            { "SUCCESS", u8"�����" },
            { "ERROR", u8"������" },
            { "INFO", u8"����������" },

            { "AimAssistance", u8"������" },
            { "Visualization", u8"������������" },
            { "Weapon", u8"������" },
            { "Miscellaneous", u8"������" },
            { "Configs", u8"������������" },
            { "General", u8"��������" },
            { "Are you sure u want to enable it?", u8"�� ����� ������ �������� ���?" },
            { "This function is ", u8"��� ������� " },
            { "dangerous!", u8"�������!" },
            { "YES", u8"��" },
            { "NO", u8"���" },
        } );
    }
};
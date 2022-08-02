# 24U_MP3_TagLib

## Id3Extractor.exe Build x64 Version 1.02

Datum 			8.2.2022
Jazyk 			C++ Version 19.32.31332 zkompilováno pro x64
Externí knihovny: 	TagLib 1.12 (open source)
			ZLib 1.2.12 (open source)
Operační systém 	Windows 10, 64 bitový
Uživatelské prostředí 	příkazová řádka
Download		https://github.com/CapeCodeInc/24U_MP3Tags_TagLib.git

Program ze zadaného MP3 souboru extrahuje název skladby a přiložený obrázek.
Vstupní soubor lze zadat jako absolutní i relativní cestu. Zadaný soubor musí existovat a musí být formátu MP3. 
Zpracování je provedeno jako projekt v MS Visual Studio 2022. Binární soubor Id3Extractor.exe jakož i použité knihovny je zkopírován do $(SolutionDir)\Binárky a zpráva.
Krátké vyzkoušení je možné spušt?ním batchového souboru $(SolutionDir)\Test\RunTest - Relative Path.bat, který program spustí a použije data přítomná p?ímo testovací složce. Program přijímá i absolutní cestu, kterou je možné zadat buď přímo v příkazovém řádku a nebo editací souboru $(SolutionDir)\Test\RunTest - Absolute Path.bat.
Výstup názvu skladby je na obrazovku. Pokud soubor neobsahuje Cover Art (přiložený obrázek), zobrazí se tato skutečnost také na obrazovce. Pokud je p?iložený obrázek přítomný, stáhne se do soubloru $(SolutionDir)\Test\ExtractedCoverArt.jpg, tedy do zkušební složky Test která je přítomna.
Protože jsem nem?l MP3 soubor ve kterém by obrázek přiložen byl, upravil jsem program tak aby Cover Art rovněž vkládal. Program lze spustit s druhým argumentem v příkazovém řádku. Pokud argv[2] je cesta k souboru formátu JPG, bude obrázek v tomto souboru do vstupního souboru vložen. 

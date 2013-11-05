/*
 *			GPAC - Multimedia Framework C SDK
 *
 *			Authors: Jean Le Feuvre 
 *			Copyright (c) Telecom ParisTech 2000-2012
 *					All rights reserved
 *
 *  This file is part of GPAC 
 *
 *  GPAC is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *   
 *  GPAC is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *   
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
 *
 */

#ifndef _GF_ISO_639_H
#define _GF_ISO_639_H


/*ISO 639 code names 
	- first string is readable english name of the language
	- second string is 3-char code of language as per ISO/IEC 639-2/T
	- third string is 2-char code of language as per ISO/IEC 639-1, and may be empty 
*/
static const char *GF_ISO639_Lang[] = 
{
	"Abkhazian","abk","ab",
	"Achinese","ace","",
	"Acoli","ach","",
	"Adangme","ada","",
	"Adyghe; Adygei","ady","",
	"Afar","aar","aa",
	"Afrihili","afh","",
	"Afrikaans","afr","af",
	"Afro-Asiatic languages","afa","",
	"Ainu","ain","",
	"Akan","aka","ak",
	"Akkadian","akk","",
	"Albanian","sqi","sq",
	"Aleut","ale","",
	"Algonquian languages","alg","",
	"Altaic languages","tut","",
	"Amharic","amh","am",
	"Angika","anp","",
	"Apache languages","apa","",
	"Arabic","ara","ar",
	"Aragonese","arg","an",
	"Arapaho","arp","",
	"Arawak","arw","",
	"Armenian","hye","hy",
	"Aromanian; Arumanian; Macedo-Romanian","rup","",
	"Artificial languages","art","",
	"Assamese","asm","as",
	"Asturian; Bable; Leonese; Asturleonese","ast","",
	"Athapascan languages","ath","",
	"Australian languages","aus","",
	"Austronesian languages","map","",
	"Avaric","ava","av",
	"Avestan","ave","ae",
	"Awadhi","awa","",
	"Aymara","aym","ay",
	"Azerbaijani","aze","az",
	"Balinese","ban","",
	"Baltic languages","bat","",
	"Baluchi","bal","",
	"Bambara","bam","bm",
	"Bamileke languages","bai","",
	"Banda languages","bad","",
	"Bantu languages","bnt","",
	"Basa","bas","",
	"Bashkir","bak","ba",
	"Basque","eus","eu",
	"Batak languages","btk","",
	"Beja; Bedawiyet","bej","",
	"Belarusian","bel","be",
	"Bemba","bem","",
	"Bengali","ben","bn",
	"Berber languages","ber","",
	"Bhojpuri","bho","",
	"Bihari languages","bih","bh",
	"Bikol","bik","",
	"Bini; Edo","bin","",
	"Bislama","bis","bi",
	"Blin; Bilin","byn","",
	"Blissymbols; Blissymbolics; Bliss","zbl","",
	"Bokmål, Norwegian; Norwegian Bokmål","nob","nb",
	"Bosnian","bos","bs",
	"Braj","bra","",
	"Breton","bre","br",
	"Buginese","bug","",
	"Bulgarian","bul","bg",
	"Buriat","bua","",
	"Burmese","mya","my",
	"Caddo","cad","",
	"Catalan; Valencian","cat","ca",
	"Caucasian languages","cau","",
	"Cebuano","ceb","",
	"Celtic languages","cel","",
	"Central American Indian languages","cai","",
	"Central Khmer","khm","km",
	"Chagatai","chg","",
	"Chamic languages","cmc","",
	"Chamorro","cha","ch",
	"Chechen","che","ce",
	"Cherokee","chr","",
	"Cheyenne","chy","",
	"Chibcha","chb","",
	"Chichewa; Chewa; Nyanja","nya","ny",
	"Chinese","zho","zh",
	"Chinook jargon","chn","",
	"Chipewyan; Dene Suline","chp","",
	"Choctaw","cho","",
	"Church Slavic; Old Slavonic; Church Slavonic; Old Bulgarian; Old Church Slavonic","chu","cu",
	"Chuukese","chk","",
	"Chuvash","chv","cv",
	"Classical Newari; Old Newari; Classical Nepal Bhasa","nwc","",
	"Classical Syriac","syc","",
	"Coptic","cop","",
	"Cornish","cor","kw",
	"Corsican","cos","co",
	"Cree","cre","cr",
	"Creek","mus","",
	"Creoles and pidgins","crp","",
	"Creoles and pidgins, English based","cpe","",
	"Creoles and pidgins, French-based","cpf","",
	"Creoles and pidgins, Portuguese-based","cpp","",
	"Crimean Tatar; Crimean Turkish","crh","",
	"Croatian","hrv","hr",
	"Cushitic languages","cus","",
	"Czech","ces","cs",
	"Dakota","dak","",
	"Danish","dan","da",
	"Dargwa","dar","",
	"Delaware","del","",
	"Dinka","din","",
	"Divehi; Dhivehi; Maldivian","div","dv",
	"Dogri","doi","",
	"Dogrib","dgr","",
	"Dravidian languages","dra","",
	"Duala","dua","",
	"Dutch, Middle (ca.1050-1350)","dum","",
	"Dutch; Flemish","nld","nl",
	"Dyula","dyu","",
	"Dzongkha","dzo","dz",
	"Eastern Frisian","frs","",
	"Efik","efi","",
	"Egyptian (Ancient)","egy","",
	"Ekajuk","eka","",
	"Elamite","elx","",
	"English","eng","en",
	"English, Middle (1100-1500)","enm","",
	"English, Old (ca.450-1100)","ang","",
	"Erzya","myv","",
	"Esperanto","epo","eo",
	"Estonian","est","et",
	"Ewe","ewe","ee",
	"Ewondo","ewo","",
	"Fang","fan","",
	"Fanti","fat","",
	"Faroese","fao","fo",
	"Fijian","fij","fj",
	"Filipino; Pilipino","fil","",
	"Finnish","fin","fi",
	"Finno-Ugrian languages","fiu","",
	"Fon","fon","",
	"French","fra","fr",
	"French, Middle (ca.1400-1600)","frm","",
	"French, Old (842-ca.1400)","fro","",
	"Friulian","fur","",
	"Fulah","ful","ff",
	"Ga","gaa","",
	"Gaelic; Scottish Gaelic","gla","gd",
	"Galibi Carib","car","",
	"Galician","glg","gl",
	"Ganda","lug","lg",
	"Gayo","gay","",
	"Gbaya","gba","",
	"Geez","gez","",
	"Georgian","kat","ka",
	"German","deu","de",
	"German, Middle High (ca.1050-1500)","gmh","",
	"German, Old High (ca.750-1050)","goh","",
	"Germanic languages","gem","",
	"Gilbertese","gil","",
	"Gondi","gon","",
	"Gorontalo","gor","",
	"Gothic","got","",
	"Grebo","grb","",
	"Greek, Ancient (to 1453)","grc","",
	"Greek, Modern (1453-)","ell","el",
	"Guarani","grn","gn",
	"Gujarati","guj","gu",
	"Gwich'in","gwi","",
	"Haida","hai","",
	"Haitian; Haitian Creole","hat","ht",
	"Hausa","hau","ha",
	"Hawaiian","haw","",
	"Hebrew","heb","he",
	"Herero","her","hz",
	"Hiligaynon","hil","",
	"Himachali languages; Western Pahari languages","him","",
	"Hindi","hin","hi",
	"Hiri Motu","hmo","ho",
	"Hittite","hit","",
	"Hmong; Mong","hmn","",
	"Hungarian","hun","hu",
	"Hupa","hup","",
	"Iban","iba","",
	"Icelandic","isl","is",
	"Ido","ido","io",
	"Igbo","ibo","ig",
	"Ijo languages","ijo","",
	"Iloko","ilo","",
	"Inari Sami","smn","",
	"Indic languages","inc","",
	"Indo-European languages","ine","",
	"Indonesian","ind","id",
	"Ingush","inh","",
	"Interlingua (International Auxiliary Language Association)","ina","ia",
	"Interlingue; Occidental","ile","ie",
	"Inuktitut","iku","iu",
	"Inupiaq","ipk","ik",
	"Iranian languages","ira","",
	"Irish","gle","ga",
	"Irish, Middle (900-1200)","mga","",
	"Irish, Old (to 900)","sga","",
	"Iroquoian languages","iro","",
	"Italian","ita","it",
	"Japanese","jpn","ja",
	"Javanese","jav","jv",
	"Judeo-Arabic","jrb","",
	"Judeo-Persian","jpr","",
	"Kabardian","kbd","",
	"Kabyle","kab","",
	"Kachin; Jingpho","kac","",
	"Kalaallisut; Greenlandic","kal","kl",
	"Kalmyk; Oirat","xal","",
	"Kamba","kam","",
	"Kannada","kan","kn",
	"Kanuri","kau","kr",
	"Kara-Kalpak","kaa","",
	"Karachay-Balkar","krc","",
	"Karelian","krl","",
	"Karen languages","kar","",
	"Kashmiri","kas","ks",
	"Kashubian","csb","",
	"Kawi","kaw","",
	"Kazakh","kaz","kk",
	"Khasi","kha","",
	"Khoisan languages","khi","",
	"Khotanese; Sakan","kho","",
	"Kikuyu; Gikuyu","kik","ki",
	"Kimbundu","kmb","",
	"Kinyarwanda","kin","rw",
	"Kirghiz; Kyrgyz","kir","ky",
	"Klingon; tlhIngan-Hol","tlh","",
	"Komi","kom","kv",
	"Kongo","kon","kg",
	"Konkani","kok","",
	"Korean","kor","ko",
	"Kosraean","kos","",
	"Kpelle","kpe","",
	"Kru languages","kro","",
	"Kuanyama; Kwanyama","kua","kj",
	"Kumyk","kum","",
	"Kurdish","kur","ku",
	"Kurukh","kru","",
	"Kutenai","kut","",
	"Ladino","lad","",
	"Lahnda","lah","",
	"Lamba","lam","",
	"Land Dayak languages","day","",
	"Lao","lao","lo",
	"Latin","lat","la",
	"Latvian","lav","lv",
	"Lezghian","lez","",
	"Limburgan; Limburger; Limburgish","lim","li",
	"Lingala","lin","ln",
	"Lithuanian","lit","lt",
	"Lojban","jbo","",
	"Low German; Low Saxon; German, Low; Saxon, Low","nds","",
	"Lower Sorbian","dsb","",
	"Lozi","loz","",
	"Luba-Katanga","lub","lu",
	"Luba-Lulua","lua","",
	"Luiseno","lui","",
	"Lule Sami","smj","",
	"Lunda","lun","",
	"Luo (Kenya and Tanzania)","luo","",
	"Lushai","lus","",
	"Luxembourgish; Letzeburgesch","ltz","lb",
	"Macedonian","mkd","mk",
	"Madurese","mad","",
	"Magahi","mag","",
	"Maithili","mai","",
	"Makasar","mak","",
	"Malagasy","mlg","mg",
	"Malay","msa","ms",
	"Malayalam","mal","ml",
	"Maltese","mlt","mt",
	"Manchu","mnc","",
	"Mandar","mdr","",
	"Mandingo","man","",
	"Manipuri","mni","",
	"Manobo languages","mno","",
	"Manx","glv","gv",
	"Maori","mri","mi",
	"Mapudungun; Mapuche","arn","",
	"Marathi","mar","mr",
	"Mari","chm","",
	"Marshallese","mah","mh",
	"Marwari","mwr","",
	"Masai","mas","",
	"Mayan languages","myn","",
	"Mende","men","",
	"Mi'kmaq; Micmac","mic","",
	"Minangkabau","min","",
	"Mirandese","mwl","",
	"Mohawk","moh","",
	"Moksha","mdf","",
	"Mon-Khmer languages","mkh","",
	"Mongo","lol","",
	"Mongolian","mon","mn",
	"Mossi","mos","",
	"Multiple languages","mul","",
	"Munda languages","mun","",
	"N'Ko","nqo","",
	"Nahuatl languages","nah","",
	"Nauru","nau","na",
	"Navajo; Navaho","nav","nv",
	"Ndebele, North; North Ndebele","nde","nd",
	"Ndebele, South; South Ndebele","nbl","nr",
	"Ndonga","ndo","ng",
	"Neapolitan","nap","",
	"Nepal Bhasa; Newari","new","",
	"Nepali","nep","ne",
	"Nias","nia","",
	"Niger-Kordofanian languages","nic","",
	"Nilo-Saharan languages","ssa","",
	"Niuean","niu","",
	"No linguistic content; Not applicable","zxx","",
	"Nogai","nog","",
	"Norse, Old","non","",
	"North American Indian languages","nai","",
	"Northern Frisian","frr","",
	"Northern Sami","sme","se",
	"Norwegian","nor","no",
	"Norwegian Nynorsk; Nynorsk, Norwegian","nno","nn",
	"Nubian languages","nub","",
	"Nyamwezi","nym","",
	"Nyankole","nyn","",
	"Nyoro","nyo","",
	"Nzima","nzi","",
	"Occitan (post 1500)","oci","oc",
	"Official Aramaic (700-300 BCE); Imperial Aramaic (700-300 BCE)","arc","",
	"Ojibwa","oji","oj",
	"Oriya","ori","or",
	"Oromo","orm","om",
	"Osage","osa","",
	"Ossetian; Ossetic","oss","os",
	"Otomian languages","oto","",
	"Pahlavi","pal","",
	"Palauan","pau","",
	"Pali","pli","pi",
	"Pampanga; Kapampangan","pam","",
	"Pangasinan","pag","",
	"Panjabi; Punjabi","pan","pa",
	"Papiamento","pap","",
	"Papuan languages","paa","",
	"Pedi; Sepedi; Northern Sotho","nso","",
	"Persian","fas","fa",
	"Persian, Old (ca.600-400 B.C.)","peo","",
	"Philippine languages","phi","",
	"Phoenician","phn","",
	"Pohnpeian","pon","",
	"Polish","pol","pl",
	"Portuguese","por","pt",
	"Prakrit languages","pra","",
	"Provençal, Old (to 1500);Occitan, Old (to 1500)","pro","",
	"Pushto; Pashto","pus","ps",
	"Quechua","que","qu",
	"Rajasthani","raj","",
	"Rapanui","rap","",
	"Rarotongan; Cook Islands Maori","rar","",
	"Reserved for local use","qaa-qtz","",
	"Romance languages","roa","",
	"Romanian; Moldavian; Moldovan","ron","ro",
	"Romansh","roh","rm",
	"Romany","rom","",
	"Rundi","run","rn",
	"Russian","rus","ru",
	"Salishan languages","sal","",
	"Samaritan Aramaic","sam","",
	"Sami languages","smi","",
	"Samoan","smo","sm",
	"Sandawe","sad","",
	"Sango","sag","sg",
	"Sanskrit","san","sa",
	"Santali","sat","",
	"Sardinian","srd","sc",
	"Sasak","sas","",
	"Scots","sco","",
	"Selkup","sel","",
	"Semitic languages","sem","",
	"Serbian","srp","sr",
	"Serer","srr","",
	"Shan","shn","",
	"Shona","sna","sn",
	"Sichuan Yi; Nuosu","iii","ii",
	"Sicilian","scn","",
	"Sidamo","sid","",
	"Sign Languages","sgn","",
	"Siksika","bla","",
	"Sindhi","snd","sd",
	"Sinhala; Sinhalese","sin","si",
	"Sino-Tibetan languages","sit","",
	"Siouan languages","sio","",
	"Skolt Sami","sms","",
	"Slave (Athapascan)","den","",
	"Slavic languages","sla","",
	"Slovak","slk","sk",
	"Slovenian","slv","sl",
	"Sogdian","sog","",
	"Somali","som","so",
	"Songhai languages","son","",
	"Soninke","snk","",
	"Sorbian languages","wen","",
	"Sotho, Southern","sot","st",
	"South American Indian languages","sai","",
	"Southern Altai","alt","",
	"Southern Sami","sma","",
	"Spanish; Castilian","spa","es",
	"Sranan Tongo","srn","",
	"Sukuma","suk","",
	"Sumerian","sux","",
	"Sundanese","sun","su",
	"Susu","sus","",
	"Swahili","swa","sw",
	"Swati","ssw","ss",
	"Swedish","swe","sv",
	"Swiss German; Alemannic; Alsatian","gsw","",
	"Syriac","syr","",
	"Tagalog","tgl","tl",
	"Tahitian","tah","ty",
	"Tai languages","tai","",
	"Tajik","tgk","tg",
	"Tamashek","tmh","",
	"Tamil","tam","ta",
	"Tatar","tat","tt",
	"Telugu","tel","te",
	"Tereno","ter","",
	"Tetum","tet","",
	"Thai","tha","th",
	"Tibetan","bod","bo",
	"Tigre","tig","",
	"Tigrinya","tir","ti",
	"Timne","tem","",
	"Tiv","tiv","",
	"Tlingit","tli","",
	"Tok Pisin","tpi","",
	"Tokelau","tkl","",
	"Tonga (Nyasa)","tog","",
	"Tonga (Tonga Islands)","ton","to",
	"Tsimshian","tsi","",
	"Tsonga","tso","ts",
	"Tswana","tsn","tn",
	"Tumbuka","tum","",
	"Tupi languages","tup","",
	"Turkish","tur","tr",
	"Turkish, Ottoman (1500-1928)","ota","",
	"Turkmen","tuk","tk",
	"Tuvalu","tvl","",
	"Tuvinian","tyv","",
	"Twi","twi","tw",
	"Udmurt","udm","",
	"Ugaritic","uga","",
	"Uighur; Uyghur","uig","ug",
	"Ukrainian","ukr","uk",
	"Umbundu","umb","",
	"Uncoded languages","mis","",
	"Undetermined","und","",
	"Upper Sorbian","hsb","",
	"Urdu","urd","ur",
	"Uzbek","uzb","uz",
	"Vai","vai","",
	"Venda","ven","ve",
	"Vietnamese","vie","vi",
	"Volapük","vol","vo",
	"Votic","vot","",
	"Wakashan languages","wak","",
	"Walloon","wln","wa",
	"Waray","war","",
	"Washo","was","",
	"Welsh","cym","cy",
	"Western Frisian","fry","fy",
	"Wolaitta; Wolaytta","wal","",
	"Wolof","wol","wo",
	"Xhosa","xho","xh",
	"Yakut","sah","",
	"Yao","yao","",
	"Yapese","yap","",
	"Yiddish","yid","yi",
	"Yoruba","yor","yo",
	"Yupik languages","ypk","",
	"Zande languages","znd","",
	"Zapotec","zap","",
	"Zaza; Dimili; Dimli; Kirdki; Kirmanjki; Zazaki","zza","",
	"Zenaga","zen","",
	"Zhuang; Chuang","zha","za",
	"Zulu","zul","zu",
	"Zuni","zun","",
	NULL
};


#endif

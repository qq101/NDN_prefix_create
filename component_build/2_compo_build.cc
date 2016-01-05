#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <fstream>
using namespace std;

const int LEN = 37; // 26 + 1 + 10
char g_arrCharElem[LEN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                           'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                           'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                           'u', 'v', 'w', 'x', 'y', 'z', '-'
                          };
const char *first_domain[623] = {
"/com",
"/edu",
"/gov",
"/int",
"/mil",
"/net",
"/org",
"/bank",
"/pro",
"/biz",
"/info",
"/name",
"/museum",
"/coop",
"/aero",
"/xxx",
"/idv",
"/ac",
"/ad",
"/ae",
"/af",
"/ag",
"/ai",
"/al",
"/am",
"/an",
"/ao",
"/aq",
"/ar",
"/as",
"/aw",
"/az",
"/ba",
"/bb",
"/bd",
"/be",
"/bf",
"/bg",
"/bh",
"/bi",
"/bn",
"/bo",
"/br",
"/bs",
"/bt",
"/bv",
"/bw",
"/by",
"/bz",
"/ca",
"/cd",
"/ch",
"/ci",
"/ck",
"/cl",
"/cm",
"/cn",
"/co",
"/cq",
"/cr",
"/cx",
"/cy",
"/cz",
"/de",
"/dj",
"/dk",
"/dm",
"/do",
"/dz",
"/tt",
"/ec",
"/ee",
"/eg",
"/eh",
"/er",
"/es",
"/et",
"/ev",
"/fi",
"/fj",
"/fo",
"/fr",
"/ga",
"/gd",
"/ge",
"/gf",
"/gg",
"/gh",
"/gi",
"/gl",
"/gp",
"/gr",
"/gs",
"/gt",
"/gu",
"/gw",
"/gy",
"/hk",
"/hm",
"/hn",
"/hu",
"/id",
"/ie",
"/il",
"/im",
"/in",
"/at",
"/au",
"/bj",
"/bm",
"/io",
"/iq",
"/ir",
"/is",
"/it",
"/jm",
"/jo",
"/jp",
"/je",
"/ke",
"/ki",
"/km",
"/kn",
"/kp",
"/kr",
"/kw",
"/ky",
"/kz",
"/la",
"/lb",
"/lk",
"/lr",
"/ls",
"/lt",
"/lu",
"/lv",
"/ly",
"/ma",
"/mc",
"/md",
"/mh",
"/mk",
"/ml",
"/mm",
"/mn",
"/mo",
"/cc",
"/cf",
"/cu",
"/cv",
"/mp",
"/mq",
"/mr",
"/ms",
"/mt",
"/mu",
"/mv",
"/mw",
"/mx",
"/my",
"/nc",
"/ne",
"/nf",
"/ng",
"/ni",
"/nl",
"/no",
"/np",
"/nr",
"/nt",
"/om",
"/qa",
"/pa",
"/pe",
"/pf",
"/pg",
"/ph",
"/pk",
"/pl",
"/pm",
"/pt",
"/pw",
"/py",
"/re",
"/rs",
"/ro",
"/fk",
"/fm",
"/gm",
"/gn",
"/ru",
"/rw",
"/sa",
"/sb",
"/sc",
"/sd",
"/se",
"/sg",
"/sh",
"/si",
"/sl",
"/sm",
"/sn",
"/so",
"/sr",
"/st",
"/sv",
"/su",
"/sy",
"/sz",
"/tf",
"/tg",
"/th",
"/tj",
"/tk",
"/tl",
"/tm",
"/tn",
"/to",
"/tr",
"/tw",
"/tz",
"/ua",
"/ug",
"/uk",
"/um",
"/hr",
"/ht",
"/kg",
"/kh",
"/us",
"/uy",
"/uz",
"/va",
"/vc",
"/ve",
"/vg",
"/vi",
"/vn",
"/vu",
"/ye",
"/yt",
"/yu",
"/yr",
"/za",
"/zm",
"/zw",
"/wf",
"/ws",
"/tv",
"/lc",
"/li",
"/tc",
"/td",
"/sj",
"/sk",
"/pn",
"/pr",
"/nu",
"/nz",
"/mz",
"/na",
"/me",
"/mg",
"/pyds",
"/mcke1",
"/gf1",
"/ma7",
"/lt2",
"/nai",
"/ba6",
"/bn2",
"/mgiuog",
"/cy6",
"/pm03",
"/dj4",
"/bvba",
"/mgr2",
"/kh2h",
"/bdzxl",
"/ye9euq",
"/sz7",
"/lculz2",
"/gsc8j",
"/sdup8",
"/pro6qg",
"/zmn",
"/cqy7z",
"/glgp4",
"/et7",
"/wfzsd",
"/ao7o6",
"/cacknk",
"/roino",
"/wfe0y",
"/mgg",
"/tfkh7s",
"/vgqhv",
"/coopiowl",
"/amb7",
"/dec",
"/maspe",
"/zmhk",
"/lv7d9e",
"/gypz27",
"/mqsdf",
"/au4",
"/guv",
"/gg04",
"/btle7",
"/mnlag",
"/fml4",
"/gov8",
"/cv1",
"/gs1djt",
"/stu9",
"/vnb",
"/tjizl3",
"/ad8q",
"/nop",
"/mtj",
"/pyd9",
"/tnsbf",
"/ch4uq",
"/fopx",
"/cyhx7",
"/maph8f",
"/org5",
"/hnf0",
"/err65t",
"/bekl89",
"/cu0",
"/wsnl",
"/rs25",
"/acxehy",
"/mnpg",
"/zwl",
"/tt1io",
"/namen6nj",
"/ma4c46",
"/ie5",
"/az2sj",
"/msgn",
"/nuls",
"/sjgsrj",
"/mtidp",
"/met8",
"/grtgc",
"/knw",
"/ischb",
"/vg3cmz",
"/pnyy",
"/smr",
"/mqh7q",
"/bojg",
"/it4h8",
"/reqy",
"/tghv",
"/aef9",
"/johc",
"/mouh1",
"/bizuk",
"/cyz",
"/ugno",
"/cq2a",
"/yrligg",
"/eg9",
"/bh9",
"/sa7kf",
"/biglu",
"/aq8i6",
"/nt8",
"/gssqg",
"/uyn0f",
"/org4",
"/gmbeez",
"/namekjp",
"/fk896k",
"/cqya1f",
"/bankiz2a",
"/sckyy",
"/skx2",
"/pnl91",
"/boae",
"/xxx5",
"/comah",
"/bywb",
"/dkyzuw",
"/net9vq7",
"/ci8pwz",
"/edur9",
"/prwzn",
"/lbj",
"/siuv24",
"/twrgry",
"/sad",
"/tjqr",
"/ugjn89",
"/idvc",
"/szv",
"/ly5",
"/neaza",
"/hnh",
"/ttl",
"/kee",
"/gpc",
"/eez7sy",
"/xxxi",
"/pf0zks",
"/pts4s",
"/snn4",
"/ciw",
"/md0suj",
"/parl",
"/kp4bq4",
"/khwlh4",
"/mo86",
"/bm8",
"/gfo1",
"/gmvp",
"/pfg",
"/ais",
"/shyu25",
"/lrnbcc",
"/dops6",
"/fivw",
"/azr",
"/uzz",
"/brj0o",
"/gfixk",
"/arn",
"/myff",
"/bn7y",
"/bf9",
"/iehjm9",
"/uk8hu",
"/mzpv4p",
"/mecg",
"/gwvpsj",
"/egn",
"/szy",
"/iql3hf",
"/req3q",
"/kpa4y",
"/kme",
"/vnajw9",
"/byw",
"/etbs",
"/lcb",
"/zwi0xm",
"/bok",
"/kgj",
"/mpd",
"/kh3",
"/soc",
"/cdp",
"/clgz",
"/imq",
"/gr9cdv",
"/jevg",
"/bwsm8",
"/ncb3y",
"/edu3tls",
"/va2",
"/tdew0r",
"/nearqq",
"/pky7",
"/hu20",
"/pm4",
"/modds2",
"/btj49",
"/hkg",
"/bgq8mw",
"/reulc7",
"/ilo",
"/mpfj",
"/gtb",
"/atlwa",
"/yuv",
"/dzawy",
"/bfdbag",
"/hrfle",
"/bimpss",
"/ltjh",
"/gm834",
"/krhde",
"/ir7",
"/pfnw5",
"/tczh",
"/awml",
"/crqd",
"/ve7znb",
"/fjsc",
"/smsq",
"/svttkb",
"/lv8ikv",
"/su49r",
"/bnyu",
"/hmely",
"/name3",
"/nl0y3",
"/intufh",
"/la1eh",
"/com7ne",
"/er8w8",
"/lbmt",
"/dm8bq",
"/fj04o",
"/clrt",
"/krre",
"/tciye",
"/dea8p",
"/luis0",
"/phrcd7",
"/mk2x",
"/fiv",
"/kiaex8",
"/com8z1w",
"/tk6",
"/cu7",
"/krekcl",
"/er3t",
"/troxue",
"/ngm4iu",
"/pkqnnx",
"/ehkhiy",
"/govjh4",
"/ngmee",
"/ket",
"/nzv",
"/slque",
"/hm19",
"/dot7",
"/orgoaq5",
"/vubg",
"/jegv",
"/srru26",
"/srk",
"/si1m",
"/sif62",
"/gpcdf",
"/cmqm9",
"/kgla9",
"/itr",
"/ky3",
"/tcw",
"/pwfie",
"/ve1",
"/pye",
"/kn1gl",
"/so3",
"/bft46",
"/cl64l",
"/ac1",
"/jmj",
"/vakw",
"/mqq",
"/ncrggy",
"/idv9usd",
"/gngm",
"/cl4x",
"/dzth",
"/au180y",
"/zat6z9",
"/tl8u11",
"/cra3",
"/tj0kki",
"/tn0il",
"/imlfl",
"/bj8",
"/orgc7",
"/gapna",
"/uzdm",
"/mq64s",
"/jespz",
"/hk0",
"/role",
"/cnby",
"/milkd",
"/itg1o",
"/cci4",
"/peb4j",
"/bo9",
"/bre",
"/adss",
"/mdq",
"/nfq8",
"/eh4n",
"/cmpnq",
"/im2z",
"/cxj5so",
"/pro9s6",
"/cfw",
"/gynf0",
"/nt3",
"/aus0d",
"/gavn",
"/me6v2",
"/mzg04n",
"/suz",
"/knmy6",
"/ieaj5",
"/gny6dt",
"/gunve5",
"/mrlma",
"/mw6o1",
"/atfjh",
"/gi0j",
"/hmx",
"/etq3",
"/gaya",
"/tl0",
"/naao0",
"/mth",
"/azx9j",
"/sk0ur0",
"/thtx",
"/au6m",
"/kin",
"/bspanq",
"/mq7x24",
"/mwfq",
"/proh1"
};


int main(int argc, char const *argv[])
{
    srand((unsigned)time(0));
    ofstream outfile;
    outfile.open("two.tmp");
    const char* input_number = argv[1];

    int num = atoi(input_number); //the total build number

    for (int i = 0; i < num; ++i)
    {
        int iDomain = 0;
        iDomain = rand() % 623;
        outfile << first_domain[iDomain];
        int iMax;

        iMax = 1; //the number of components

        for (int i = 0; i < iMax; i++) {
            int iLen;

            iLen = rand() % 9 + 5; //the string's length of each component

            char* szStr = new char[iLen + 1];
            szStr[iLen] = '\0';
            int iRand = 0;
            for (int i = 0; i < iLen; ++i)
            {
                iRand = rand() % LEN;            // iRand = 0 - 36
                szStr[i] = g_arrCharElem[iRand];
            }
            outfile << "/" << szStr;
            delete[] szStr;
        }
        outfile << endl;
    }
    outfile.close();
    return 0;
}
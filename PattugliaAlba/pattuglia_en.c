/* Adventure Writing System, file generated by aws2c */

#include<stdio.h>
#include<stdlib.h>
#define DIR_REDUCED
#include"aws.h"

#include"inout.h"
#include"systemdef.h"

extern unsigned int verb;
extern unsigned int noun1;
extern unsigned int noun2;
extern unsigned int adve;
extern unsigned int actor;
extern unsigned int adjective;
unsigned int dummy;
#define CARRIED 1500
#define WEARED 1600

char *compressed;
unsigned char bpointer;
unsigned int cpointer;
#define B_SIZE 200
char decompress_b[B_SIZE+1];
unsigned char currbyte;

unsigned char g_b(void)
{
   unsigned int t;
   if(bpointer==0) {
       currbyte=compressed[cpointer];
   }
   if(++bpointer==8) {
       bpointer=0;
       ++cpointer;
   }
   t=currbyte&0x1;
   currbyte>>=1;
   return t;
}

#define NUM_NODES 109
tree huftree[NUM_NODES]={
    {75,255,255},
    {90,255,255},
    {255,0,1},
    {66,255,255},
    {113,255,255},
    {255,3,4},
    {71,255,255},
    {76,255,255},
    {255,6,7},
    {77,255,255},
    {255,9,5},
    {70,255,255},
    {255,11,2},
    {80,255,255},
    {255,13,8},
    {67,255,255},
    {255,15,12},
    {106,255,255},
    {255,10,17},
    {85,255,255},
    {255,19,14},
    {34,255,255},
    {72,255,255},
    {255,21,22},
    {69,255,255},
    {87,255,255},
    {255,24,25},
    {78,255,255},
    {63,255,255},
    {255,27,28},
    {68,255,255},
    {255,30,16},
    {58,255,255},
    {255,32,18},
    {255,20,23},
    {255,26,29},
    {107,255,255},
    {118,255,255},
    {255,36,37},
    {65,255,255},
    {83,255,255},
    {255,39,40},
    {33,255,255},
    {255,31,42},
    {82,255,255},
    {44,255,255},
    {255,44,45},
    {39,255,255},
    {255,33,47},
    {89,255,255},
    {79,255,255},
    {255,49,50},
    {98,255,255},
    {255,34,52},
    {255,35,41},
    {255,38,43},
    {73,255,255},
    {255,46,56},
    {84,255,255},
    {255,48,58},
    {102,255,255},
    {255,51,60},
    {112,255,255},
    {103,255,255},
    {255,62,63},
    {119,255,255},
    {255,65,53},
    {109,255,255},
    {255,67,54},
    {121,255,255},
    {255,55,69},
    {46,255,255},
    {255,57,71},
    {99,255,255},
    {255,59,73},
    {117,255,255},
    {255,61,75},
    {108,255,255},
    {255,64,77},
    {0,255,255},
    {255,79,66},
    {100,255,255},
    {255,68,81},
    {255,70,72},
    {105,255,255},
    {255,84,74},
    {104,255,255},
    {255,76,86},
    {110,255,255},
    {255,78,88},
    {114,255,255},
    {115,255,255},
    {255,90,91},
    {255,80,82},
    {97,255,255},
    {255,94,83},
    {116,255,255},
    {255,96,85},
    {111,255,255},
    {101,255,255},
    {255,98,99},
    {255,87,89},
    {255,92,93},
    {255,95,97},
    {32,255,255},
    {255,100,104},
    {255,101,102},
    {255,103,105},
    {255,106,107},
};

char hufget(void)
{
    unsigned int i=NUM_NODES-1;
    while(1) {
        if(huftree[i].c!=255)
            return huftree[i].c;
        if(g_b()==0) {
            i=huftree[i].son0idx;
        } else {
            i=huftree[i].son1idx;
        }
    }
    return 0;
}

void decode_start(char *source)
{
    cpointer=0;
    bpointer=0;
    compressed=source;
}
char decode(void)
{
    char c;
    unsigned int k=0;
    do {
        c=hufget();
        SHIFTPETSCII;
        decompress_b[k++]=c;
    } while(c!='\0'&&k<B_SIZE);
    if(k>=B_SIZE) {
        decompress_b[k]='\0';
        return 1;
    }
    return 0;
}
#define DSIZE 58
word dictionary[DSIZE]={
    {"TO",150,0},
    {"LIGHT",37,1},
    {"UP",84,1},
    {"OPEN",112,1},
    {"WARNING",61,2},
    {"DOWN",85,1},
    {"STOP",40,1},
    {"HARNESS",6,2},
    {"CHARGE",989,1},
    {"RIDE",100,1},
    {"HORSE",7,2},
    {"SEARCH",36,1},
    {"CLOSE",113,1},
    {"CHAIN",3,2},
    {"E",82,1},
    {"HELMET",2,2},
    {"ENTER",31,1},
    {"EXAMINE",70,1},
    {"EAST",82,1},
    {"POKE",36,1},
    {"FIRE",60,2},
    {"D",110,1},
    {"DOWN",85,1},
    {"LOOK",110,1},
    {"I",72,2},
    {"WEAR",115,1},
    {"STICK",39,1},
    {"INSERT",39,1},
    {"INVENTORY",72,2},
    {"LEAVE",55,1},
    {"READ",70,1},
    {"PUT",39,1},
    {"RIDE",100,1},
    {"SHOW",74,1},
    {"N",80,1},
    {"NORD",80,1},
    {"W",83,1},
    {"WEST",83,1},
    {"STRAW",59,2},
    {"BENCH",58,2},
    {"GRAB",50,1},
    {"THEN",9999,3},
    {"DOOR",114,2},
    {"LEAVE",55,1},
    {"TAKE",50,1},
    {"THEN",9999,3},
    {"RESTART",987,1},
    {"S",81,1},
    {"CLIMB",101,1},
    {"SAVE",988,1},
    {"SADDLE",5,2},
    {"DOWN",75,0},
    {"SWORD",4,2},
    {"TURN",38,1},
    {"UP",84,1},
    {"SOUTH",81,1},
    {"TORCH",1,2},
    {"GO",100,1}
};

char long_d1[]={0xD9,0x87,0xF3,0xC6,0x2F,0xDC,0xF7,0xA1,0x45,0xB7,0x53,0xDF,0xF,0x94,0x4A,0x43,0x7C,0xFE,0x2E,0xEE,0xB5,0xC2,0x4E,0x57,0x1F,0xB2,0x8F,0xFA,0x86,0xD6,0x83,0xFD,0x83,0x1F,0xD2,0xA3,0x15,0xE9,0xE9,0x86,0xD7,0xD7,0xBC,0x70,0x6F,0xAD,0xD6,0x89,0x50,0x6D,0x4C,0x1E,0xB2,0x5F,0x79,0xE1,0x9E,0x84,0x21,0xFE,0xC4,0x68,0xE5,0x7,0xF2,0xB,0xF7,0x3C,0x52,0x98,0xF9,0x38,0x48,0x1B,0x89,0xF5,0x1,0xAF,0x15,0x4D,0xF4,0xE4,0x96,0x1E,0x12,0xAF,0xB1,0x42,0xBC,0xBE,0x70,0xDF,0x87,0x16,0xDD,0x4E,0xFD,0x72,0x49,0x70,0xBF,0xF9,0xBB,0xB8,0xF,0x71,0x46,0xD2,0xFB,0x19,0x79,0xD3,0xD7,0xBC,0x70,0xAF,0x3,0xB,0x73,0x3};
char s_desc1[]={0x6};
char short_d1[]={0x49,0x1,0x6D,0x64,0x74,0x1,0x6E,0x19,0x49,0xC};
char long_d2[]={0x5D,0xDC,0x87,0x38,0x23,0xE9,0x9B,0x3E,0xDE,0xF,0xF5,0xF,0xF6,0xF7,0x21,0x9,0xEF,0x31,0x1C,0xFB,0x4A,0xFE,0x6C,0xBD,0x1F,0xAE,0x68,0xAC,0xF,0x4A,0x9F,0xD0,0xD8,0xEB,0x7,0xBC,0xB5,0x41,0xC,0x6B,0xE6,0xB5,0x46,0xD6,0x7F,0xF8,0x56,0x50,0x7A,0x89,0x3E,0x41,0xF3,0x77,0x71,0x65,0xDF,0xF4,0x71,0x3F,0x23,0xAF,0x79,0xE1,0x9E,0x47,0xA,0x73,0x3};
char s_desc2[]={0x6};
char short_d2[]={0x6E,0x19,0x1D,0x1,0x66,0x0,0xC};
char long_d3[]={0xD9,0x87,0xF3,0xC6,0x2F,0xDC,0xF7,0xA1,0x45,0xB7,0x53,0xAF,0x15,0x76,0xBA,0x9A,0xDF,0x6,0xFB,0x95,0x3B,0xE9,0xC1,0xDD,0x7A,0xE1,0xCA,0xBE,0xE9,0xE3,0x34,0xD2,0x95,0xF,0x78,0x50,0x56,0xF1,0x5A,0x12,0x56,0x7E,0x37,0xFE,0x10,0xCB,0x8D,0xC9,0xD3,0xD,0xAF,0xAF,0x79,0xE1,0x7E,0x43,0x2B,0xF3,0x35,0x56,0x88,0xD7,0x17,0xEE,0x31,0x28,0xBD,0x85,0x2B,0x7B,0x1C,0xD1,0xD5,0x87,0xEC,0x15,0xC7,0xE7,0xEF,0xE2,0xBE,0x1F,0x28,0x95,0x86,0xF8,0x37,0x7D,0xCD,0xB,0xF7,0xD6,0x6A,0xE5,0x6};
char s_desc3[]={0x6};
char short_d3[]={0xEE,0x5D,0xB7,0x8E,0xB2,0xB9,0xB,0x77,0x3};
char long_d4[]={0xB6,0x57,0xF6,0x4D,0x5F,0xB8,0x97,0x19,0xE7,0x16,0xAE,0xEC,0x71,0x44,0x57,0x1F,0xB2,0x57,0x1C,0x9F,0x3F,0x23,0xFA,0x4,0x7D,0xB0,0x3F,0xB1,0xA4,0x3E,0x61,0x97,0x78,0x50,0xFA,0x84,0xC6,0xFE,0x3,0x1E,0x47,0x74,0x2F,0xCD,0x37,0x26,0xBF,0x1D,0xD,0x1B,0xE1,0x2C,0x57,0x7E,0xF7,0xA,0x3B,0x5D,0x7D,0xC8,0xBE,0xE6,0x85,0x7B,0x6B,0xB5,0x72,0x3};
char s_desc4[]={0x6};
char short_d4[]={0xB6,0x81,0x19,0xEE,0x2E,0xEE,0x6E,0x1B,0xE8,0xE2,0x19,0x40,0x60,0x47,0xC};
char long_d5[]={0x6E,0xF5,0xC2,0x7D,0xD,0xF1,0x1,0xAF,0x15,0x4D,0xF4,0x4D,0x5F,0xB8,0x5F,0x2E,0x9,0xEE,0xF7,0x3,0xBE,0x70,0xDF,0x87,0x16,0xDD,0xFC,0x5D,0x6B,0xAE,0x43,0x7D,0x5B,0xD1,0x87,0xEC,0xB5,0x82,0x7D,0x63,0xF2,0xB8,0xB2,0xAF,0x39,0x9,0x43,0xFC,0xB,0xF7,0xCB,0x25,0xC1,0xFD,0xE6,0xEF,0xE2,0xA6,0xC7,0xA1,0xFE,0x65,0xCD,0xE9,0x30,0x79,0x25,0x36,0x44,0xDF,0xCB,0xA8,0xAE,0x7F,0xE3,0x83,0x32,0x5C,0x1F,0xF0,0x85,0xFB,0x21,0x96,0xEF,0x67,0x24,0x7F,0xF6,0x7D,0xF0,0x75,0xF7,0x85,0xFB,0x42,0x19,0xDE,0xCB,0x8C,0xF3,0x9A,0x17,0xEE,0x79,0xC4,0x3F,0xD8,0x67,0xDE,0xBE,0xD8,0xD8,0xDF,0xD9,0xCC,0x17,0xEE,0xB5,0xA2,0x89,0x9E,0x6E,0xF8,0xFB,0xB1,0xF8,0x35,0x2F,0xDC,0xF7,0x3,0xA5,0xD2,0x10,0x9F,0x1B};
char s_desc5[]={0x6};
char short_d5[]={0x40,0x57,0xEF,0x2,0x6D,0x3A,0x30,0x69,0x77,0xEF,0xBA,0x65,0x33,0xDC,0xD};
char long_d6[]={0xD9,0x87,0x73,0xC8,0x7E,0xE5,0x85,0xFB,0x90,0x1E,0x3F,0xE0,0xB,0xF7,0x24,0xC,0xF1,0x27,0x46,0x2B,0x7F,0xF6,0x7D,0xF0,0x75,0x37,0xF3,0x20,0x94,0xC2,0x95,0xD7,0xBC,0x70,0x6F,0xAD,0x56,0xE6,0xB,0xF7,0x38,0xA2,0x7B,0x22,0x4A,0x86,0x3E,0xFB,0x70,0xAE,0x90,0x20,0x46,0xD7,0xBF,0xE6,0x1D,0x4F,0xE3,0xFC,0x6E,0x57,0x27,0x28,0xBD,0x9F,0x91,0xD3,0xD,0xAF,0xE7,0x91,0xC2,0x37,0xAE,0x79,0xE1,0x9E,0x84,0x21,0xFE,0xC4,0x68,0xE5,0xEF,0xE2,0xBE,0x1F,0x28,0x95,0x86,0xF8,0x37,0x7D,0xCD,0xB,0xF7,0x1B,0x5A,0xB9,0x1};
char s_desc6[]={0x6};
char short_d6[]={0x36,0x5C,0x25,0x71,0x91,0xF1,0xAE,0x6D,0x17,0x77,0xCB,0x48,0xCA,0xB6,0x4B,0x37,0x80,0x1};
char long_d7[]={0x5D,0x6C,0xFA,0x80,0x5A,0x2B,0x7B,0x99,0x71,0xDE,0xF4,0x85,0x7B,0x12,0x86,0xF8,0x13,0xA3,0x95,0xBF,0x8B,0xFB,0x61,0x9A,0xBE,0x1F,0x7,0x1C,0x29,0x7D,0xC8,0x3E,0x6E,0x5F,0xEE,0x31,0xF3,0xF1,0xA,0x3B,0xDD,0x7,0xFB,0xC7,0xC1,0x26,0x7B,0xC,0x82,0x68,0x34,0x7D,0x2F,0xD1,0x27,0x34,0x26,0x6F,0x85,0x38,0x8D,0xC9,0x43,0xE2,0x85,0x7B,0x82,0x46,0xBF,0xF9,0x81,0xFC,0xE1,0xBD,0x15,0x94,0xBE,0x70,0x65,0xDF,0xF4,0x71,0x2B,0x84,0x1B,0x93,0xB9,0x1};
char s_desc7[]={0x6};
char short_d7[]={0x36,0xB3,0xE1,0x96,0x91,0xE4,0x36,0x1,0xDD,0xBB,0x6};
char long_d8[]={0x80,0x81,0xF,0xD9,0xC7,0x75,0xA8,0x6F,0x2B,0x1F,0xF0,0x49,0xD7,0x98,0x7C,0xD2,0xF,0xD9,0xA9,0xF,0x71,0xD2,0x7,0xFB,0xA7,0x3,0x8F,0x91,0xB8,0xAF,0x39,0x39,0x1F,0x58,0x1F,0x7E,0x1C,0x47,0x74,0x4F,0x44,0xC9,0xD0,0x37,0x7E,0x1C,0x5C,0xEB,0x4E,0x63,0x58,0xAB,0xF9,0xDD,0xC7,0xD9,0xF,0xF8,0x74,0xA0,0x1C,0x5C,0x4A,0xC7,0x3A,0x21,0xC1,0x9,0x5A,0x2B,0x7A,0x8C,0xC4,0x3D,0x36,0xEF,0x97,0x9F,0xE,0x94,0xE3,0x52,0x67,0xEB,0xC1,0xFE,0xE9,0x40,0x79,0x8F,0xD1,0xF8,0x4E,0x34,0x9A,0x79,0x9D,0xA7,0x3,0xEF,0x40,0xAD,0x83,0x8D,0xFD,0xB,0xD7,0xB9,0x7D,0xC1,0x91,0x7D,0xC7,0xD3,0xB8,0x31,0xF9,0x74,0xA0,0x1C,0x5C,0x4A,0xC7,0xBA,0x34,0xBF,0xA2,0xF9,0xDD,0xD8,0xDF,0xBE,0xE0,0xC8,0xBE,0x70,0xDF,0x8F,0xE3,0x4,0xFB,0x95,0xF3,0x54,0xEB,0xF7,0xE9,0x40,0x79,0xD8,0x75,0xB9,0xDF,0x64,0x3};
char s_desc8[]={0x6};
char short_d8[]={0x59,0x57,0xDD,0xC,0x60,0x12,0x1B,0x49,0x75,0xB3,0x40,0x57,0x6};
#define RSIZE 8
room world[RSIZE]={
    {1,long_d1,s_desc1,short_d1,{0,0,3,6,5,0,}},
    {2,long_d2,s_desc2,short_d2,{0,0,0,0,0,0,}},
    {3,long_d3,s_desc3,short_d3,{0,0,4,1,0,0,}},
    {4,long_d4,s_desc4,short_d4,{0,0,0,3,0,0,}},
    {5,long_d5,s_desc5,short_d5,{0,0,0,0,0,1,}},
    {6,long_d6,s_desc6,short_d6,{7,0,1,0,0,0,}},
    {7,long_d7,s_desc7,short_d7,{0,6,0,0,0,0,}},
    {8,long_d8,s_desc8,short_d8,{0,0,0,0,0,0,}}
};

char message1[]={0x5D,0xDC,0xFB,0x19,0x79,0xD3,0xF7,0x74,0x74,0x7D,0x6E,0x0};
char message2[]={0x5D,0xDC,0xFB,0x19,0x79,0xD3,0xF,0xB1,0x6C,0x0};
char message3[]={0x5D,0xDC,0xFB,0x19,0x79,0xD3,0xF,0xB1,0xDC,0x98,0xCC,0xF3,0xDC,0x0};
char message4[]={0x80,0x81,0xEF,0xE9,0xE8,0xBE,0x70,0xEF,0x67,0xE4,0x85,0x51,0x57,0x1A,0x8E,0xDE,0x6A,0x85,0x8F,0x93,0xB2,0x51,0xE7,0x69,0xBA,0xB9,0x1};
char message5[]={0x80,0x81,0xEF,0x83,0x3B,0xEB,0x7E,0x5E,0x18,0x95,0x1B};
char message6[]={0x80,0x81,0xEF,0x83,0x3B,0xEB,0x74,0x23,0x71,0x5F,0xB8,0xEF,0x43,0x8B,0xEE,0xED,0xE9,0xC1,0x99,0x4A,0x36,0x0};
char message7[]={0x5D,0xDC,0xEB,0x72,0x35,0x5E,0xAA,0xD7,0x1A,0xE2,0xE9,0xC0,0x7,0xFB,0xF,0xEF,0x7,0x7C,0xE1,0x3A,0x4F,0x97,0x52,0xED,0x70,0x5B,0xEE,0xCD,0x21,0xE8,0x5E,0x87,0xFA,0xB6,0xA2,0xEF,0x83,0xCF,0x53,0x27,0xB7,0xDE,0xF8,0x85,0xFB,0x2E,0xCA,0xF0,0x3E,0x63,0xC6,0xC9,0x6D,0x19};
char message8[]={0x36,0x9F,0x49,0xB8,0x85,0x51,0xB7,0xF6,0xE0,0x40,0xF6,0xC7,0x95,0x75,0xFD,0x6C,0xBD,0xE9,0xD3,0x81,0x72,0x5C,0xEA,0x6C,0xE5,0x79,0x6E,0x0};
char message9[]={0x80,0x81,0xD7,0xD,0xE9,0xF1,0x8D,0x5F,0xB8,0xD7,0x92,0xB0,0x32,0xF,0x36,0xF6,0x8D,0xC9,0x7,0x7F,0xEC,0x1D,0x6F,0x5F,0x79,0x9E,0x1B};
char message10[]={0x80,0x81,0x27,0x60,0xBD,0x70,0x5F,0x8D,0xF8,0x80,0x2F,0xDC,0xD7,0x48,0x8F,0x6F,0xFC,0xC2,0x3D,0xD8,0x64,0xF3,0x67,0xEB,0x7D,0x54,0x8F,0xAB,0x7,0x9B,0xEC,0x13,0x57,0xD2,0x4B,0x10,0xCD,0xD3,0x34,0x37,0x0};
char message11[]={0x80,0x81,0xF7,0xC3,0x9D,0x75,0xB0,0xB1,0x7F,0x70,0x5A,0xD8,0x98,0x3C,0xD4,0x5,0x21,0xCD,0xD};
char message12[]={0x80,0x81,0xF7,0xC3,0x9D,0x75,0xDD,0x7D,0x70,0x5A,0xD8,0x98,0xBC,0x12,0xDB,0xB7,0xA0,0xB9,0x1};
char message14[]={0x5D,0xDC,0xD7,0x48,0x8F,0x6F,0x7A,0x9E,0xBA,0x1D,0xA,0x37,0x26,0x73,0x3};
char message15[]={0x5D,0xDC,0xD7,0x48,0x8F,0x6F,0x7A,0x3B,0x14,0x6E,0x4C,0xE6,0x6};
char message16[]={0x6E,0xB7,0x42,0xB8,0x31,0xF9,0xE1,0x17,0xEE,0xAD,0xA0,0xF4,0x1A,0xA9,0x76,0x78,0x12,0xE0,0x5D,0x1,0xBB,0x77,0xB7,0x29,0xDB,0x3D,0xD0,0xD5,0x93,0x96,0xCD,0x70,0x91,0x6C,0x0};
char message18[]={0x5D,0xDC,0xE3,0x88,0xEE,0x9B,0x9E,0xA7,0xAE,0xE1,0x3D,0x5D,0x9F,0x1B};
char message19[]={0x5D,0xDC,0xE3,0x88,0xEE,0x9B,0x9E,0xA7,0x8E,0x21,0xBC,0xAA,0xEB,0x73,0x3};
char message20[]={0x80,0x81,0xF7,0xC3,0x9D,0x75,0x8C,0xC4,0x7D,0x3A,0x50,0xAE,0xD6,0x88,0xCF,0xD};
char message21[]={0x80,0x81,0xF7,0xC3,0x9D,0x75,0x6B,0x43,0x5E,0xB8,0xEF,0x31,0x1A,0xDF,0x89,0x46,0x73,0x3};
char message22[]={0x80,0x81,0x27,0xB7,0x3E,0xFC,0xC2,0x3D,0x8E,0xE8,0x3E,0xD8,0xBF,0x64,0xEA,0x3,0x4B,0x9B,0xDF,0x17,0xEE,0xFB,0xD0,0xA2,0x9B,0xF9,0x8E,0xA7,0x71,0x63,0xF2,0xE9,0x40,0xB9,0x13,0xB5,0xFA,0xC6,0xAF,0xE6,0xEC,0xC1,0x91,0x17,0xEE,0x9D,0x11,0x6E,0x4C,0x9E,0x88,0x92,0xA1,0xB9,0x1};
char message23[]={0x80,0x81,0xF7,0xC3,0x9D,0x75,0x6B,0x43,0x9E,0xE,0x94,0xE3,0x52,0x67,0x2B,0x37,0x0};
char message30[]={0x2E,0xB1,0xF5,0x78,0x9E,0x5A,0xD7,0x6};
char message31[]={0x2E,0xB1,0xF5,0x78,0x1C,0xD1,0x75,0x6D,0x0};
char message33[]={0x6E,0xA7,0x3,0xFD,0x13,0xA7,0xF5,0xFB,0xED,0x71,0x56,0xCF,0x1B,0x62,0x4F,0x3B,0xDC,0x96,0xFB,0x50,0xDF,0x56,0xEE,0xEE,0xB4,0xC2,0xE4,0xBB,0xC4,0x95,0x7D,0xC8,0x3E,0x1D,0x78,0x6C,0xBE,0x31,0x99,0x79,0x1D,0xA9,0xF,0x78,0x84,0x4E,0xF0,0xC9,0x10,0x7B,0x90,0xEB,0xDA,0xD6,0xD};
char message34[]={0x80,0x81,0xC7,0xD,0x39,0x38,0x53,0x5A,0x4B,0xE8,0xED,0x8B,0x8D,0xFD,0xD3,0x81,0xF,0xF6,0x8F,0x93,0x32,0xB0,0xC7,0xF4,0x89,0xD3,0xFA,0xBD,0xE2,0xC0,0xD2,0xE,0xB7,0x65,0x7B,0x65,0x9F,0xE,0x7C,0xC8,0x26,0xBF,0x8B,0x32,0xD6,0xB1,0x39,0x6F,0xFC,0xC2,0x7D,0x1F,0x5A,0x74,0x3B,0xF5,0x1E,0x32,0xB9,0xC3,0x7A,0x70,0xE4,0x3C,0x75,0xC5,0xB1,0x1A,0x93,0x87,0x44,0xB2,0xAD,0xFC,0x5D,0x6B,0xDE,0x8F,0x10,0x90,0x2E,0xD7,0x75,0xA8,0x6F,0x2B,0xFA,0xD5,0x7E,0xA4,0x9E,0xE,0x7C,0xCD,0xB,0xF7,0x1E,0x32,0xB9,0xC3,0xFA,0x60,0x7F,0x3A,0x7D,0xC2,0xD3,0x81,0x6F,0xFC,0x78,0xBF,0x94,0xE6,0x7,0xC,0xBC,0x12,0xCB,0xF5,0x9A,0xB9,0x3,0x7B,0x7C,0x35,0x67,0x1F,0xEC,0x9F,0xE,0x3C,0x18,0x8D,0xAE,0xBF,0xD3,0x74,0x25,0xEC,0x34,0x4D,0x36,0x0};
char message35[]={0x5D,0xDC,0xE3,0xE8,0xBE,0xE9,0xE3,0x4E,0x90,0xDC,0xC0,0xD6,0x2F,0xD7,0x43,0xC2,0x7E,0xAD,0xA0,0xB4,0xD,0x67,0xDE,0x3E,0xC2,0xAF,0x79,0x1F,0x22,0xE9,0xAD,0x10,0x69,0x23,0x7A,0xDA,0x12,0xF6,0xE9,0xC0,0xDC,0x0};
char message1000[]={0xC0,0x84,0x48,0x73,0x3};
char message1001[]={0x49,0x86,0x37,0x37,0x0};
char message1002[]={0x49,0x86,0x37,0x37,0x0};
char message1003[]={0xD9,0x7A,0xD3,0xD7,0xCC,0x71,0x23,0x31,0x4D,0x36,0x0};
char message1004[]={0xD9,0x7A,0xD3,0xD7,0xCC,0xED,0x8D,0x7C,0xCD,0xED,0x7B,0xC,0xF6,0x74,0x7D,0xB2,0x1};
char message1005[]={0xD9,0xBA,0x9F,0xD5,0xF3,0xD4,0x9D,0x49,0xDC,0x64,0x3};
char message1006[]={0xD9,0xFB,0xE1,0xCE,0xBA,0xEE,0xBE,0x30,0xEA,0xC1,0xA9,0x85,0x2B,0x9B,0x6C,0x0};
char message1007[]={0xD9,0xFB,0xE1,0xCE,0x3A,0x46,0xE2,0xBE,0x30,0xEA,0x56,0x2B,0xBC,0xB3,0xC9,0x6};
char message1008[]={0xD9,0xF7,0xC1,0x9D,0x75,0x72,0x5E,0x18,0x75,0x2B,0xD2,0x64,0x3};
char message1009[]={0x2E,0x31,0xEA,0x7E,0x9E,0xE,0xBC,0xB3,0xC1,0xAE,0xD};
char message1010[]={0xD9,0xF7,0xC1,0x9D,0x75,0x3F,0x2F,0x8C,0xCA,0xD};
char message1011[]={0xD9,0x7,0x95,0xD,0x9F,0x1E,0x23,0x71,0x5F,0x18,0x75,0xAB,0x15,0xDE,0xD9,0x64,0x3};
char message1012[]={0x2E,0x31,0xEA,0x8A,0x41,0xE9,0xB3,0xF7,0xE3,0xDA,0x0};
char message1013[]={0xD9,0x7A,0xD3,0xFB,0x90,0x84,0xCC,0x67,0xDF,0x7,0x9F,0xA7,0xAE,0xBB,0xF,0x4E,0xB,0x1B,0x93,0x6};
char message1014[]={0x80,0x81,0x27,0x68,0xA4,0xEB,0xF,0x8E,0xDC,0x0};
char message1015[]={0x2F,0x28,0xAC,0xAF,0xF9,0xD8,0x2B,0x1A,0xDF,0x0};
char message1016[]={0x27,0xA6,0x71,0x69,0x6E,0x0};
char message1018[]={0xD6,0x8,0x1B};
char message1019[]={0xD9,0x87,0xF3,0xA0,0xB2,0xE1,0xD3,0x5B,0x1B,0xD2,0x98,0x7C,0x61,0x54,0x6E,0x0};
char message1020[]={0xD9,0xF7,0xC1,0x27,0xE7,0x35,0x56,0x88,0xD7,0xE,0x6};
char message1021[]={0x3C,0x52,0x68,0x0};
char message1022[]={0x3A,0xB0,0xD0,0x0};
char message1023[]={0x1B,0x5A,0x6};
char message1024[]={0xD6,0x6A,0x19};
char message1025[]={0x90,0x30,0x0};
char message1026[]={0x7E,0x2C,0x36,0x0};
char message1027[]={0x3C,0x52,0xB8,0xA1,0x65,0x0};
char message1028[]={0x3C,0x52,0x68,0xAD,0x96,0x1};
char message1029[]={0x3A,0xB0,0x70,0x43,0xCB,0x0};
char message1030[]={0x3A,0xB0,0x70,0x12,0x57,0xCB,0x0};
char message1031[]={0xD9,0xF7,0xC1,0xD7,0xDD,0xE,0x37,0x0};
char message1032[]={0xD9,0xF7,0x21,0x92,0x76,0xB8,0x1};
char message1033[]={0xD9,0xFB,0xE1,0xCE,0x3A,0x46,0xE2,0x3E,0x38,0x2D,0x6C,0x4C,0xDE,0x6A,0x85,0x77,0x36,0x37,0x0};
char message1035[]={0xF6,0xD0,0xA,0x3};
#define MSIZE 60
message msg[MSIZE]={
    {1,message1},
    {2,message2},
    {3,message3},
    {4,message4},
    {5,message5},
    {6,message6},
    {7,message7},
    {8,message8},
    {9,message9},
    {10,message10},
    {11,message11},
    {12,message12},
    {14,message14},
    {15,message15},
    {16,message16},
    {18,message18},
    {19,message19},
    {20,message20},
    {21,message21},
    {22,message22},
    {23,message23},
    {30,message30},
    {31,message31},
    {33,message33},
    {34,message34},
    {35,message35},
    {1000,message1000},
    {1001,message1001},
    {1002,message1002},
    {1003,message1003},
    {1004,message1004},
    {1005,message1005},
    {1006,message1006},
    {1007,message1007},
    {1008,message1008},
    {1009,message1009},
    {1010,message1010},
    {1011,message1011},
    {1012,message1012},
    {1013,message1013},
    {1014,message1014},
    {1015,message1015},
    {1016,message1016},
    {1018,message1018},
    {1019,message1019},
    {1020,message1020},
    {1021,message1021},
    {1022,message1022},
    {1023,message1023},
    {1024,message1024},
    {1025,message1025},
    {1026,message1026},
    {1027,message1027},
    {1028,message1028},
    {1029,message1029},
    {1030,message1030},
    {1031,message1031},
    {1032,message1032},
    {1033,message1033},
    {1035,message1035}
};

char desc_l1[]={0xF1,0x1A,0xE9,0x31,0xF3,0x3,0xCB,0x0};
char desc_l2[]={0x71,0x5C,0xEA,0x6C,0x19};
char desc_l3[]={0xF1,0x1E,0xA3,0xF1,0x9D,0x68,0xD4,0x0};
char desc_l4[]={0x71,0xB5,0x46,0xBC,0x1};
char desc_l5[]={0x71,0xD,0xEF,0xE9,0x1A};
char desc_l6[]={0x71,0xC,0xE1,0x55,0x35,0x0};
char desc_l7[]={0x71,0x1C,0xD1,0x35,0x0};
char desc_l8[]={0x71,0xDA,0xEA,0x35,0xD2,0xA3,0x1};
#define OSIZE 8
object obj[OSIZE]={
    {1,"",desc_l1,0,0,5,true,true},
    {2,"",desc_l2,0,0,0,true,false},
    {3,"",desc_l3,0,0,0,true,false},
    {4,"",desc_l4,0,0,2,true,true},
    {5,"",desc_l5,0,0,4,true,true},
    {6,"",desc_l6,0,0,4,true,true},
    {7,"",desc_l7,100,0,3,true,true},
    {8,"",desc_l8,0,0,0,true,true}
};

unsigned int current_position;
unsigned int next_position;
extern unsigned int ls;
boolean marker[129];
int counter[129];
object *odummy;

unsigned int search_object(unsigned int o)
{
    unsigned int i;
    for(i=0; i<OSIZE;++i)
        if(obj[i].code==o)
            return i;
    return 0;
}

unsigned int search_room(unsigned int r)
{
    unsigned int i;
    for(i=0; i<RSIZE;++i)
        if(world[i].code==r)
            return i;
    return 0;
}

void write_textsl(char *m)
{
    char r;
    decode_start(m);
    do {
        r=decode();
        writesameln(decompress_b);
    } while(r!=0);
}
void write_text(char *m)
{
    write_textsl(m);
    writeln("");
}
void show_messagenlf(unsigned int m)
{
    unsigned int i;
    for(i=0; i<MSIZE;++i)
        if(msg[i].code==m){
            write_textsl(msg[i].txt);
            break;
        }
}

void show_message(unsigned int m)
{
    show_messagenlf(m);
    writeln("");
}

void inventory(void)
{
    unsigned int i, gs=0;
    show_message(1032);
    for(i = 0; i<OSIZE; ++i) {
        if(obj[i].position==CARRIED||obj[i].position==WEARED) {
            ++gs;
            evidence2();
            write_textsl(obj[i].desc);
            normaltxt();
            if(obj[i].position==WEARED){
                writesameln("  ");
                show_messagenlf(1018);
            }
            writeln("");
        }
    }
    if(gs==0) show_message(1033);
}

unsigned int move(unsigned int dir)
{
    if(world[search_room(current_position)].directions[dir]!=0) {
        next_position=world[search_room(current_position)].directions[dir];
        marker[120]=false;
        return 1;
    } else 
        show_message(1008);
    return 0;
}

unsigned int get(unsigned int o)
{
    dummy=search_object(o);
    odummy=&obj[dummy];
    if(odummy->position!=current_position) {
        show_message(1006);
        return 1;
    } else if(odummy->isnotmovable==false) {
        show_message(1005);
        return 1;
    } else if(counter[120]+odummy->weight>counter[122]){ 
        show_message(1003);
            return 1;
    } else if(counter[124]+odummy->size>counter[121]) {
        show_message(1004);
        return 1;
    } else {
        odummy->position=CARRIED;
        ++counter[119];
        counter[120]+=odummy->weight;
        counter[124]+=odummy->size;
    }
    return 0;
}
boolean vov(unsigned int v1, unsigned int v2)
{
    return verb==v1||verb==v2;
}
boolean vovn(unsigned int v1, unsigned int v2, unsigned int n)
{
    return (verb==v1||verb==v2)&&noun1==n;
}
boolean non1(unsigned int n1, unsigned int n2)
{
    return noun1==n1||noun1==n2;
}
boolean cvn(unsigned int v, unsigned int n)
{
    return verb==v&&noun1==n;
}
unsigned int get_object_position(unsigned int c)
{
    return obj[search_object(c)].position;
}
boolean object_is_here(unsigned int c)
{
    return obj[search_object(c)].position==current_position;
}
boolean object_is_carried(unsigned int c)
{
    return obj[search_object(c)].position==CARRIED;
}
boolean object_is_available(unsigned int c)
{
    return object_is_here(c)||object_is_carried(c);
}
void set_object_position(unsigned int c, int pos)
{
    obj[search_object(c)].position=pos;
}
void bring_object_here(unsigned int c)
{
    set_object_position(c,current_position);
}
void amsm(unsigned int p, unsigned char c, boolean v, unsigned int m)
{
    if(current_position==p&&marker[c]==v) show_message(m);
}
unsigned int cvna(unsigned int v, unsigned int n, unsigned int o)
{
    dummy=get_object_position(o);
    return verb==v&&noun1==n&&(dummy==current_position||dummy==CARRIED);
}
void drop(unsigned int o)
{
    dummy=search_object(o);
    odummy=&obj[dummy];
    if(odummy->position==CARRIED){
        odummy->position=current_position;
        --counter[119];
        counter[120]-=odummy->weight;
        counter[124]-=odummy->size;
    } else
        show_message(1007);
}

void jump(unsigned int p)
{
    next_position=p;
    marker[120]=false;
}

void hold(unsigned int p)
{
    for(dummy=0; dummy<p; ++dummy) {wait1s();}
}

void greetings(void)
{
    evidence2();
    writeln("Patrol at the dawn\n");
    writesameln("Aristide Torrelli");
    writeln("  2014\n");
    writeln("From a type-in program found in a computing magazine of 1980's\n");
    writesameln("AWS ");
    writeln("3.0");
    normaltxt();
    waitkey();
}
unsigned int hi_cond(void)
{
    // if res? 50 then set 50 rese 124 endif
    if(marker[50]==false) {
        marker[50]=true;
        marker[124]=false;
    }

    // IF at 8 AND res? 8 THEN set 8 goto 1 ENDIF
    if(current_position==8) if(marker[8]==false) {
        marker[8]=true;
        jump(1);
        goto return1;
    }

    // if at 1 and res? 11 then mess 1 endif
    if(1) amsm(1,11,0,1);    // if at 1 and set? 11 then mess 2 endif
    if(1) amsm(1,11,1,2);    // if at 2 and res? 11 then mess 1 endif
    if(1) amsm(2,11,0,1);    // if at 2 and set? 11 then mess 2 endif
    if(1) amsm(2,11,1,2);    // if at 2 and carr 8 then set 122 endif
    if(current_position==2) if(object_is_carried(8)) {
        marker[122]=true;
    }

    // if at 2 and here 8 then set 122 endif
    if(current_position==2) if(object_is_here(8)) {
        marker[122]=true;
    }

    // if at 2 and notcarr 8 then rese 122 endif
    if(current_position==2) if(object_is_carried(8)==false) {
        marker[122]=false;
    }

    // if at 2 and nothere 8 then rese 122 endif
    if(current_position==2) if(object_is_here(8)==false) {
        marker[122]=false;
    }

    // IF carr 8 THEN set 122 ENDIF  ho la torcia accesa
    if(object_is_carried(8)) {
        marker[122]=true;
    }

    // IF res? 16 and ctreq 126 0 then cset 126 61 ENDIF  
    if(marker[16]==false) if(counter[126]==0) {
        counter[126]=61;
    }

    // IF res? 16 and ctreq 126 10 then mess 33 ENDIF  
    if(marker[16]==false) if(counter[126]==10) {
        show_message(33);
    }

    // IF res? 16 and ctreq 126 1 then mess 34 quit ENDIF
    if(marker[16]==false) if(counter[126]==1) {
        show_message(34);
        leave(); exit(0);
    }

    return 0;
    return1: return 1;
}
unsigned int low_cond(void)
{
    // if verb 40 then quit endif
    if(verb==40) {
        leave(); exit(0);
    }

    // if verb 74 and noun 72 then inve wait endif
    if(cvn(74,72)) {
        inventory();
        goto return1;
    }

    // if verb 0 and noun 72 then inve wait endif
    if(cvn(0,72)) {
        inventory();
        goto return1;
    }

    // if verb 987 then restart endif
    if(verb==987) {
    }

    // if verb 988 then save wait endif salva la partita
    if(verb==988) {
        goto return1;
    }

    // if verb 989 then load wait endif carica la partita
    if(verb==989) {
        goto return1;
    }

    // if verb  80 then nord wait endif
    if(verb==80) {
        move(0);
        goto return1;
    }

    // if verb 81 then sud wait endif
    if(verb==81) {
        move(1);
        goto return1;
    }

    // if verb 82 then est wait endif
    if(verb==82) {
        move(2);
        goto return1;
    }

    // if verb 83 then ovest wait endif
    if(verb==83) {
        move(3);
        goto return1;
    }

    // if verb 84 then alto wait endif
    if(verb==84) {
        move(4);
        goto return1;
    }

    // if verb 85 then basso wait endif
    if(verb==85) {
        move(5);
        goto return1;
    }

    // if verb 110 then look wait endif
    if(verb==110) {
        marker[120]=false;
        goto return1;
    }

    // IF VERB 50 AND NO1LT 9 THEN GET NO1 OKAY ENDIF
    if(verb==50) if((noun1>0&&noun1<9)) {
        if(get(noun1)!=0) goto return1;
        show_message(1000);
        goto return1;
    }

    // IF VERB 55 AND NO1LT 9 THEN DROP NO1 OKAY ENDIF
    if(verb==55) if((noun1>0&&noun1<9)) {
        drop(noun1);
        show_message(1000);
        goto return1;
    }

    // IF verb 110 AND noun 58 THEN mess 1009 WAIT ENDIF  GUARDA  PANCA
    if(cvn(110,58)) {
        show_message(1009);
        goto return1;
    }

    // IF verb 36 AND noun 59 THEN mess 1009 WAIT ENDIF  CERCA  PAGLIA
    if(cvn(36,59)) {
        show_message(1009);
        goto return1;
    }

    // IF verb 37 AND noun 1 THEN mess 1010 WAIT ENDIF  ACCENDI  TORCIA
    if(cvn(37,1)) {
        show_message(1010);
        goto return1;
    }

    // IF verb 38 AND noun 1 AND carr 8 AND res? 121 THEN swap 8 1 rese 122 look WAIT ENDIF  SPEGNI  TORCIA  
    if(cvn(38,1)) if(object_is_carried(8)) if(marker[121]==false) {
        dummy=get_object_position(8);
        obj[search_object(8)].position=obj[search_object(1)].position;
        obj[search_object(1)].position=dummy;
        marker[122]=false;
        marker[120]=false;
        goto return1;
    }

    // IF VERB 38 AND NOUN 1 AND CARR 8 AND Set? 121 THEN SWAP 8 1 RESE 122 okay ENDIF  SPEGNI  TORCIA     SPEGNI  TORCIA  
    if(cvn(38,1)) if(object_is_carried(8)) if(marker[121]==true) {
        dummy=get_object_position(8);
        obj[search_object(8)].position=obj[search_object(1)].position;
        obj[search_object(1)].position=dummy;
        marker[122]=false;
        show_message(1000);
        goto return1;
    }

    // IF VERB 38 AND NOUN 1 AND CARR 1 THEN mess 14 WAIT ENDIF  SPEGNI  TORCIA     SPEGNI  TORCIA  
    if(cvn(38,1)) if(object_is_carried(1)) {
        show_message(14);
        goto return1;
    }

    // IF VERB 38 AND NOUN 1 THEN MESS 1010 WAIT ENDIF  SPEGNI  TORCIA     SPEGNI  TORCIA     SPEGNI  TORCIA     SPEGNI  TORCIA
    if(cvn(38,1)) {
        show_message(1010);
        goto return1;
    }

    // IF VERB 70 AND NOUN 61 THEN MESS 30 WAIT ENDIF  LEGGI  AVVISO     LEGGI  AVVISO
    if(cvn(70,61)) {
        show_message(30);
        goto return1;
    }

    // IF verb 100 AND noun 7 THEN mess 31 WAIT ENDIF  MONTA  CAVALLO
    if(cvn(100,7)) {
        show_message(31);
        goto return1;
    }

    // IF verb 70 AND noun 7 THEN mess 31 WAIT ENDIF  ESAMINA  CAVALLO
    if(cvn(70,7)) {
        show_message(31);
        goto return1;
    }

    // IF verb 115 AND noun 2 AND carr 2 THEN wear 2 okay ENDIF  INDOSSA  ELMETTO  
    if(cvn(115,2)) if(object_is_carried(2)) {
        dummy=search_object(2);
        odummy=&obj[dummy];
        if(odummy->isnotwereable==false&&odummy->position==CARRIED){
            odummy->position=WEARED;
            ++counter[118];
        } else if(odummy->position==WEARED) {
            show_message(1019);
            goto return1;
        } else {
            show_message(1010);
            goto return1;
        }
        show_message(1000);
        goto return1;
    }

    // IF VERB 115 AND NOUN 3 AND CARR 3 THEN WEAR 3 OKAY ENDIF  INDOSSA  ELMETTO     INDOSSA  COTTA DI MAGLI
    if(cvn(115,3)) if(object_is_carried(3)) {
        dummy=search_object(3);
        odummy=&obj[dummy];
        if(odummy->isnotwereable==false&&odummy->position==CARRIED){
            odummy->position=WEARED;
            ++counter[118];
        } else if(odummy->position==WEARED) {
            show_message(1019);
            goto return1;
        } else {
            show_message(1010);
            goto return1;
        }
        show_message(1000);
        goto return1;
    }

    return 0;
    return1: return 1;
}
unsigned int local_cond(void)
{
    switch(current_position) {
    case 1:
    // IF verb 81 and RES? 11 THEN  MESS 5 MESS 1 WAIT ENDIF
    if(verb==81) if(marker[11]==false) {
        show_message(5);
        show_message(1);
        goto return1;
    }

    // IF verb 81 AND set? 11 THEN rese 121 goto 2 WAIT ENDIF  SUD
    if(verb==81) if(marker[11]==true) {
        marker[121]=false;
        jump(2);
        goto return1;
    }

    // IF verb 112 AND noun 114 AND res? 11 THEN set 11  mess 3 WAIT ENDIF  APRI  PORTA
    if(cvn(112,114)) if(marker[11]==false) {
        marker[11]=true;
        show_message(3);
        goto return1;
    }

    // IF verb 113 AND noun 114 AND set? 11 THEN rese 11 mess 4 WAIT ENDIF    APRI  PORTA  CHIUDI  PORTA
    if(cvn(113,114)) if(marker[11]==true) {
        marker[11]=false;
        show_message(4);
        goto return1;
    }

    break;
    case 2:
    // IF verb 80 AND set? 11 THEN set 121 goto 1 WAIT ENDIF  NORD
    if(verb==80) if(marker[11]==true) {
        marker[121]=true;
        jump(1);
        goto return1;
    }

    // IF verb 112 AND noun 114 AND res? 11 THEN set 11  mess 3 WAIT ENDIF  APRI  PORTA
    if(cvn(112,114)) if(marker[11]==false) {
        marker[11]=true;
        show_message(3);
        goto return1;
    }

    // IF verb 113 AND noun 114 AND set? 11 THEN rese 11 mess 4 WAIT ENDIF    APRI  PORTA  CHIUDI  PORTA
    if(cvn(113,114)) if(marker[11]==true) {
        marker[11]=false;
        show_message(4);
        goto return1;
    }

    break;
    case 3:
    // IF verb 36 AND noun 59 AND res? 13 THEN mess 9 brin 3 set 13 WAIT ENDIF  CERCA  PAGLIA
    if(cvn(36,59)) if(marker[13]==false) {
        show_message(9);
        bring_object_here(3);
        marker[13]=true;
        goto return1;
    }

    // IF verb 36 AND noun 59 AND set? 13 THEN mess 11 WAIT ENDIF  CERCA  PAGLIA
    if(cvn(36,59)) if(marker[13]==true) {
        show_message(11);
        goto return1;
    }

    // IF verb 100 and noun 7 and ISNOTWEARING 2 THEN MESS 23 WAIT ENDIF
    if(cvn(100,7)) if(get_object_position(2)!=WEARED) {
        show_message(23);
        goto return1;
    }

    // IF verb 100 and noun 7 and isnotwearing 3 THEN mess 21 WAIT ENDIF
    if(cvn(100,7)) if(get_object_position(3)!=WEARED) {
        show_message(21);
        goto return1;
    }

    // IF verb 100 and noun 7 and notcarr 4 THEN mess 20 WAIT ENDIF
    if(cvn(100,7)) if(object_is_carried(4)==false) {
        show_message(20);
        goto return1;
    }

    // IF verb 100 and noun 7 and res? 14 THEN mess 18 WAIT ENDIF
    if(cvn(100,7)) if(marker[14]==false) {
        show_message(18);
        goto return1;
    }

    // IF verb 100 and noun 7 and res? 15 THEN mess 19 WAIT ENDIF
    if(cvn(100,7)) if(marker[15]==false) {
        show_message(19);
        goto return1;
    }

    // IF verb 100 and noun 7 THEN set 16 mess 22 quit ENDIF
    if(cvn(100,7)) {
        marker[16]=true;
        show_message(22);
        leave(); exit(0);
    }

    // IF verb 39 AND noun 5 AND  no2eq 7 AND carr 5 THEN set 14 to 5 8 okay ENDIF  metti SELLA  CAVALLO
    if(cvn(39,5)) if(noun2==7) if(object_is_carried(5)) {
        marker[14]=true;
        set_object_position(5,8);
        show_message(1000);
        goto return1;
    }

    // IF verb 39 AND noun 6 AND no2eq 7 AND carr 6 THEN set 15 to 6 8 okay ENDIF  METTI  BRIGLIE  CAVALLO
    if(cvn(39,6)) if(noun2==7) if(object_is_carried(6)) {
        marker[15]=true;
        set_object_position(6,8);
        show_message(1000);
        goto return1;
    }

    // IF verb 70 AND noun 7 THEN mess 35 ENDIF
    if(cvn(70,7)) {
        show_message(35);
    }

    // IF res? 14 THEN mess 18 ENDIF
    if(marker[14]==false) {
        show_message(18);
    }

    // IF res? 15 THEN mess 19 ENDIF
    if(marker[15]==false) {
        show_message(19);
    }

    // IF verb 70 AND noun 7 THEN wait ENDIF
    if(cvn(70,7)) {
        goto return1;
    }

    break;
    case 7:
    // IF verb 110 AND noun 58 AND adve 75 AND res? 12 THEN mess 8 brin 2 WAIT ENDIF  GUARDA  PANCA  SOTTO
    if(cvn(110,58)) if(adve==75) if(marker[12]==false) {
        show_message(8);
        bring_object_here(2);
        goto return1;
    }

    // IF verb 110 AND noun 58 AND res? 12 THEN mess 8 brin 2 WAIT ENDIF  GUARDA  PANCA  SOTTO
    if(cvn(110,58)) if(marker[12]==false) {
        show_message(8);
        bring_object_here(2);
        goto return1;
    }

    // IF verb 37 AND noun 1 AND carr 8 THEN mess 15 WAIT ENDIF  ACCENDI  TORCIA
    if(cvn(37,1)) if(object_is_carried(8)) {
        show_message(15);
        goto return1;
    }

    // IF verb 37 AND noun 1 AND carr 1 THEN mess 10 swap 1 8 WAIT ENDIF  ACCENDI  TORCIA
    if(cvn(37,1)) if(object_is_carried(1)) {
        show_message(10);
        dummy=get_object_position(1);
        obj[search_object(1)].position=obj[search_object(8)].position;
        obj[search_object(8)].position=dummy;
        goto return1;
    }

    // IF verb 70 AND noun 61 THEN mess 16 WAIT ENDIF  LEGGI  AVVISO
    if(cvn(70,61)) {
        show_message(16);
        goto return1;
    }

    }
    return 0;
    return1: return 1;
}

void game_cycle(void)
{
    unsigned int k;
    boolean ve,pa;
    while(1){
        current_position=next_position;
        if(marker[120]==false&&(marker[121]==true||marker[122]==true)) {
        writeln("");
        evidence1();
            write_textsl(world[search_room(current_position)].short_d);
        writesameln("  ");
        normaltxt();
            write_text(world[search_room(current_position)].long_d);
            writeln("");
            marker[120]=true;
            ve=false;
            for(k=0;k<OSIZE;++k)
                if(obj[k].position==current_position) {
                    if(ve==false) {
                        show_message(1031);
                        ve=true;
                        evidence2();
                    }
                    write_textsl(obj[k].desc);
                }
                normaltxt();
            if(marker[124]==true) {
                pa=false;
            for(k=0; k<6; ++k)
                if(world[search_room(current_position)].directions[k]!=0) {
                    if(pa==false) {
                        show_messagenlf(1020);
                        pa=true;
                    }
                    evidence3();
                    show_messagenlf(1021+k);
                    writesameln(" ");
                }
                normaltxt();
                writeln("");
            }
        }
        ++counter[125];
        --counter[126];
        --counter[127];
        --counter[128];
        if(hi_cond()!=0) continue;
        writeln("");
        if(ls==0) show_message(1012);
        interrogationAndAnalysis(DSIZE);
        if(local_cond()!=0) continue;
        if(low_cond()!=0) continue;
        show_message(verb==0?1009:1010);
    }
}

int main(void)
{
    init_term();
    greetings();
    next_position=8;
    marker[124]=true;
    marker[121]=true;
    counter[121]=10000;
    counter[122]=10000;
    game_cycle();
    return 0;
}

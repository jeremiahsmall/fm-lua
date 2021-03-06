#include "lua.h"
#include "lauxlib.h"
#include "lualtn12scripts.h"

static const unsigned char B1[]={
 27, 76,117, 97, 81,  0,  1,  4,  4,  4,  8,  0, 11,  0,  0,  0, 64,108,116,110,
 49, 50, 46,108,117, 97,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  7, 94,
  0,  0,  0,  5,  0,  0,  0, 65, 64,  0,  0, 28,128,  0,  1, 69,  0,  0,  0,129,
128,  0,  0, 92,128,  0,  1,133,192,  0,  0,197,  0,  1,  0,  1, 65,  1,  0,220,
 64,  0,  1,202,  0,  0,  0,199,128,  1,  0,202,  0,  0,  0,199,192,  1,  0,202,
  0,  0,  0,199,  0,  2,  0,202,  0,  0,  0,199, 64,  2,  0,193,192,  2,  0,199,
128,  2,  0,193, 64,  3,  0,199,  0,  3,  0,197,128,  1,  0, 36,  1,  0,  0,  0,
  0,  0,  1,201,  0,  1,135,197,128,  1,  0, 36, 65,  0,  0,  0,  0,128,  0,  0,
  0,  0,  1,201,  0,129,135,228,128,  0,  0,  5,193,  1,  0,100,193,  0,  0,  0,
  0,128,  1,  9, 65,  1,136,  5,193,  1,  0,100,  1,  1,  0,  9, 65,129,136,  5,
193,  1,  0,100, 65,  1,  0,  9, 65,  1,137,  5,193,  1,  0,100,129,  1,  0,  0,
  0,  0,  1,  9, 65,129,137,  5,193,  1,  0,100,193,  1,  0,  0,  0,  0,  0,  9,
 65,129,128,  5,193,  1,  0,100,  1,  2,  0,  0,  0,  0,  1,  0,  0,128,  0,  9,
 65,  1,138,  5,193,  1,  0,100, 65,  2,  0,  0,  0,  0,  1,  9, 65,129,135,  5,
193,  1,  0,100,129,  2,  0,  0,  0,128,  0,  9, 65,129,138,  5,  1,  2,  0,100,
193,  2,  0,  0,  0,128,  0,  9, 65,  1,129,  5,  1,  2,  0,100,  1,  3,  0,  0,
  0,  0,  1,  9, 65,129,137,  5,  1,  2,  0,100, 65,  3,  0,  9, 65,  1,137, 36,
129,  3,  0, 69,  1,  2,  0,164,193,  3,  0,  0,  0,  0,  2, 73,129,  1,139, 69,
  1,  2,  0,164,  1,  4,  0, 73,129,129,136, 69,  1,  2,  0,164, 65,  4,  0,  0,
  0,  0,  1, 73,129,129,135, 69, 65,  2,  0,164,129,  4,  0, 73,129,129,139, 69,
 65,  2,  0,164,193,  4,  0,  0,  0,  0,  1, 73,129,  1,140, 30,  0,128,  0, 25,
  0,  0,  0,  4,  8,  0,  0,  0,114,101,113,117,105,114,101,  0,  4,  7,  0,  0,
  0,115,116,114,105,110,103,  0,  4,  6,  0,  0,  0,116, 97, 98,108,101,  0,  4,
  3,  0,  0,  0, 95, 71,  0,  4,  7,  0,  0,  0,109,111,100,117,108,101,  0,  4,
  6,  0,  0,  0,108,116,110, 49, 50,  0,  4,  7,  0,  0,  0,102,105,108,116,101,
114,  0,  4,  7,  0,  0,  0,115,111,117,114, 99,101,  0,  4,  5,  0,  0,  0,115,
105,110,107,  0,  4,  5,  0,  0,  0,112,117,109,112,  0,  4, 10,  0,  0,  0, 66,
 76, 79, 67, 75, 83, 73, 90, 69,  0,  3,  0,  0,  0,  0,  0,  0,160, 64,  4,  9,
  0,  0,  0, 95, 86, 69, 82, 83, 73, 79, 78,  0,  4, 12,  0,  0,  0, 76, 84, 78,
 49, 50, 32, 49, 46, 48, 46, 49,  0,  4,  6,  0,  0,  0, 99,121, 99,108,101,  0,
  4,  6,  0,  0,  0, 99,104, 97,105,110,  0,  4,  6,  0,  0,  0,101,109,112,116,
121,  0,  4,  6,  0,  0,  0,101,114,114,111,114,  0,  4,  5,  0,  0,  0,102,105,
108,101,  0,  4,  9,  0,  0,  0,115,105,109,112,108,105,102,121,  0,  4,  7,  0,
  0,  0,114,101,119,105,110,100,  0,  4,  4,  0,  0,  0, 99, 97,116,  0,  4,  5,
  0,  0,  0,110,117,108,108,  0,  4,  5,  0,  0,  0,115,116,101,112,  0,  4,  4,
  0,  0,  0, 97,108,108,  0, 20,  0,  0,  0,  0,  0,  0,  0, 29,  0,  0,  0, 36,
  0,  0,  0,  1,  3,  0,  5, 10,  0,  0,  0,196,  0,  0,  0,198,  0,192,  1,  0,
  1,  0,  0,220, 64,  0,  1,228,  0,  0,  0,  0,  0,128,  0,  0,  0,  0,  0,  0,
  0,  0,  1,222,  0,  0,  1, 30,  0,128,  0,  1,  0,  0,  0,  4,  7,  0,  0,  0,
 97,115,115,101,114,116,  0,  1,  0,  0,  0,  0,  0,  0,  0, 31,  0,  0,  0, 35,
  0,  0,  0,  3,  1,  0,  6,  9,  0,  0,  0,132,  0,128,  0,196,  0,  0,  0,  0,
  1,  0,  0, 68,  1,  0,  1,156,192,  0,  2,200,  0,  0,  0, 64,  0,  0,  1, 94,
  0,  0,  1, 30,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0, 33,
  0,  0,  0, 33,  0,  0,  0, 33,  0,  0,  0, 33,  0,  0,  0, 33,  0,  0,  0, 33,
  0,  0,  0, 33,  0,  0,  0, 34,  0,  0,  0, 35,  0,  0,  0,  2,  0,  0,  0,  6,
  0,  0,  0, 99,104,117,110,107,  0,  0,  0,  0,  0,  8,  0,  0,  0,  4,  0,  0,
  0,114,101,116,  0,  0,  0,  0,  0,  8,  0,  0,  0,  3,  0,  0,  0,  4,  0,  0,
  0, 99,116,120,  0,  4,  0,  0,  0,108,111,119,  0,  6,  0,  0,  0,101,120,116,
114, 97,  0, 10,  0,  0,  0, 30,  0,  0,  0, 30,  0,  0,  0, 30,  0,  0,  0, 30,
  0,  0,  0, 35,  0,  0,  0, 35,  0,  0,  0, 35,  0,  0,  0, 35,  0,  0,  0, 35,
  0,  0,  0, 36,  0,  0,  0,  3,  0,  0,  0,  4,  0,  0,  0,108,111,119,  0,  0,
  0,  0,  0,  9,  0,  0,  0,  4,  0,  0,  0, 99,116,120,  0,  0,  0,  0,  0,  9,
  0,  0,  0,  6,  0,  0,  0,101,120,116,114, 97,  0,  0,  0,  0,  0,  9,  0,  0,
  0,  1,  0,  0,  0,  5,  0,  0,  0, 98, 97,115,101,  0,  0,  0,  0,  0, 40,  0,
  0,  0, 67,  0,  0,  0,  2,  0,  7,  6, 16,  0,  0,  0, 68,  0,  0,  0, 70,  0,
192,  0,128,  0,  0,  0, 92,128,  0,  1,129, 64,  0,  0,193, 64,  0,  0,  1,129,
  0,  0,100,  1,  0,  0,  0,  0,  0,  2,  0,  0,128,  1,  0,  0,  0,  1,  0,  0,
  0,  0,  0,  0,128,  0,  4,  0,128,  0, 94,  1,  0,  1, 30,  0,128,  0,  3,  0,
  0,  0,  4,  5,  0,  0,  0,103,101,116,110,  0,  3,  0,  0,  0,  0,  0,  0,240,
 63,  4,  1,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0, 44,  0,  0,  0, 66,
  0,  0,  0,  6,  1,  0,  3, 67,  0,  0,  0, 91,  0,  0,  0, 22,  0,  0,128, 68,
  0,  0,  0, 72,  0,  0,  0, 68,  0,128,  0,132,  0,  0,  1, 23,128,128,  0, 22,
 64,  6,128, 68,  0,128,  1,132,  0,128,  0, 70,128,128,  0,128,  0,  0,  0, 92,
128,  0,  1,  0,  0,128,  0, 87,  0, 64,  0, 22,192,  0,128, 68,  0,  0,  1,132,
  0,  0,  2, 23,128,128,  0, 22, 64,  0,128, 30,  0,  0,  1, 22, 64,251,127, 26,
  0,  0,  0, 22,192,  0,128, 68,  0,128,  0, 76, 64,192,  0, 72,  0,128,  0, 22,
192,249,127, 68,  0,  0,  1, 76, 64,192,  0, 72,  0,  0,  1, 68,  0,  0,  1, 72,
  0,128,  0, 22, 64,248,127, 68,  0,128,  1,132,  0,128,  0, 70,128,128,  0,155,
 64,  0,  0, 22,  0,  0,128,129,  0,  0,  0, 92,128,  0,  1,  0,  0,128,  0, 23,
  0, 64,  0, 22,  0,  1,128, 68,  0,128,  0, 77, 64,192,  0, 72,  0,128,  0,  4,
  0,  0,  0, 22,128,244,127, 26,  0,  0,  0, 22, 64,  2,128, 68,  0,128,  0,132,
  0,  0,  2, 23,128,128,  0, 22, 64,  0,128, 30,  0,  0,  1, 22,128,242,127, 68,
  0,128,  0, 76, 64,192,  0, 72,  0,128,  0, 22,128,241,127, 68,  0,128,  2, 70,
128,192,  0,129,192,  0,  0, 92, 64,  0,  1, 22, 64,240,127, 30,  0,128,  0,  4,
  0,  0,  0,  4,  1,  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,240, 63,  4,  6,
  0,  0,  0,101,114,114,111,114,  0,  4, 34,  0,  0,  0,102,105,108,116,101,114,
 32,114,101,116,117,114,110,101,100, 32,105,110, 97,112,112,114,111,112,114,105,
 97,116,101, 32,110,105,108,  0,  0,  0,  0,  0, 67,  0,  0,  0, 45,  0,  0,  0,
 45,  0,  0,  0, 45,  0,  0,  0, 45,  0,  0,  0, 47,  0,  0,  0, 47,  0,  0,  0,
 47,  0,  0,  0, 47,  0,  0,  0, 48,  0,  0,  0, 48,  0,  0,  0, 48,  0,  0,  0,
 48,  0,  0,  0, 48,  0,  0,  0, 48,  0,  0,  0, 49,  0,  0,  0, 49,  0,  0,  0,
 49,  0,  0,  0, 49,  0,  0,  0, 49,  0,  0,  0, 49,  0,  0,  0, 49,  0,  0,  0,
 49,  0,  0,  0, 50,  0,  0,  0, 50,  0,  0,  0, 50,  0,  0,  0, 50,  0,  0,  0,
 50,  0,  0,  0, 50,  0,  0,  0, 52,  0,  0,  0, 52,  0,  0,  0, 52,  0,  0,  0,
 53,  0,  0,  0, 53,  0,  0,  0, 54,  0,  0,  0, 56,  0,  0,  0, 56,  0,  0,  0,
 56,  0,  0,  0, 56,  0,  0,  0, 56,  0,  0,  0, 56,  0,  0,  0, 56,  0,  0,  0,
 56,  0,  0,  0, 57,  0,  0,  0, 57,  0,  0,  0, 58,  0,  0,  0, 58,  0,  0,  0,
 58,  0,  0,  0, 59,  0,  0,  0, 59,  0,  0,  0, 60,  0,  0,  0, 60,  0,  0,  0,
 61,  0,  0,  0, 61,  0,  0,  0, 61,  0,  0,  0, 61,  0,  0,  0, 61,  0,  0,  0,
 61,  0,  0,  0, 62,  0,  0,  0, 62,  0,  0,  0, 62,  0,  0,  0, 62,  0,  0,  0,
 63,  0,  0,  0, 63,  0,  0,  0, 63,  0,  0,  0, 63,  0,  0,  0, 64,  0,  0,  0,
 66,  0,  0,  0,  1,  0,  0,  0,  6,  0,  0,  0, 99,104,117,110,107,  0,  0,  0,
  0,  0, 66,  0,  0,  0,  6,  0,  0,  0,  6,  0,  0,  0,114,101,116,114,121,  0,
  6,  0,  0,  0,105,110,100,101,120,  0,  4,  0,  0,  0,116,111,112,  0,  4,  0,
  0,  0, 97,114,103,  0,  2,  0,  0,  0,110,  0,  5,  0,  0,  0, 98, 97,115,101,
  0, 16,  0,  0,  0, 41,  0,  0,  0, 41,  0,  0,  0, 41,  0,  0,  0, 41,  0,  0,
  0, 42,  0,  0,  0, 42,  0,  0,  0, 43,  0,  0,  0, 66,  0,  0,  0, 66,  0,  0,
  0, 66,  0,  0,  0, 66,  0,  0,  0, 66,  0,  0,  0, 66,  0,  0,  0, 66,  0,  0,
  0, 66,  0,  0,  0, 67,  0,  0,  0,  5,  0,  0,  0,  4,  0,  0,  0, 97,114,103,
  0,  0,  0,  0,  0, 15,  0,  0,  0,  2,  0,  0,  0,110,  0,  4,  0,  0,  0, 15,
  0,  0,  0,  4,  0,  0,  0,116,111,112,  0,  6,  0,  0,  0, 15,  0,  0,  0,  6,
  0,  0,  0,105,110,100,101,120,  0,  6,  0,  0,  0, 15,  0,  0,  0,  6,  0,  0,
  0,114,101,116,114,121,  0,  7,  0,  0,  0, 15,  0,  0,  0,  2,  0,  0,  0,  6,
  0,  0,  0,116, 97, 98,108,101,  0,  5,  0,  0,  0, 98, 97,115,101,  0,  0,  0,
  0,  0, 73,  0,  0,  0, 75,  0,  0,  0,  0,  0,  0,  2,  2,  0,  0,  0, 30,  0,
  0,  1, 30,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0, 74,  0,
  0,  0, 75,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 77,  0,
  0,  0, 79,  0,  0,  0,  1,  0,  0,  2,  3,  0,  0,  0,  4,  0,  0,  0, 30,  0,
  0,  1, 30,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0, 78,  0,
  0,  0, 78,  0,  0,  0, 79,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  6,  0,
  0,  0,101,109,112,116,121,  0,  0,  0,  0,  0, 82,  0,  0,  0, 86,  0,  0,  0,
  0,  1,  0,  2,  4,  0,  0,  0,100,  0,  0,  0,  0,  0,  0,  0, 94,  0,  0,  1,
 30,  0,128,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0, 83,  0,  0,  0,
 85,  0,  0,  0,  1,  0,  0,  2,  3,  0,  0,  0, 68,  0,  0,  0, 30,  0,128,  1,
 30,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0, 84,  0,  0,  0,
 84,  0,  0,  0, 85,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  4,  0,  0,  0,
101,114,114,  0,  4,  0,  0,  0, 85,  0,  0,  0, 85,  0,  0,  0, 85,  0,  0,  0,
 86,  0,  0,  0,  1,  0,  0,  0,  4,  0,  0,  0,101,114,114,  0,  0,  0,  0,  0,
  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 89,  0,  0,  0, 97,  0,  0,  0,
  0,  2,  0,  4, 14,  0,  0,  0, 26,  0,  0,  0, 22,192,  0,128,164,  0,  0,  0,
  0,  0,  0,  0,158,  0,  0,  1, 22,128,  1,128,133,  0,  0,  0,134, 64, 64,  1,
219, 64,128,  0, 22,  0,  0,128,193,128,  0,  0,157,  0,  0,  1,158,  0,  0,  0,
 30,  0,128,  0,  3,  0,  0,  0,  4,  7,  0,  0,  0,115,111,117,114, 99,101,  0,
  4,  6,  0,  0,  0,101,114,114,111,114,  0,  4, 20,  0,  0,  0,117,110, 97, 98,
108,101, 32,116,111, 32,111,112,101,110, 32,102,105,108,101,  0,  1,  0,  0,  0,
  0,  0,  0,  0, 91,  0,  0,  0, 95,  0,  0,  0,  1,  0,  0,  3, 11,  0,  0,  0,
  4,  0,  0,  0, 11,  0, 64,  0,133, 64,  0,  0, 28,128,128,  1, 26, 64,  0,  0,
 22,128,  0,128, 68,  0,  0,  0, 75,128,192,  0, 92, 64,  0,  1, 30,  0,  0,  1,
 30,  0,128,  0,  3,  0,  0,  0,  4,  5,  0,  0,  0,114,101, 97,100,  0,  4, 10,
  0,  0,  0, 66, 76, 79, 67, 75, 83, 73, 90, 69,  0,  4,  6,  0,  0,  0, 99,108,
111,115,101,  0,  0,  0,  0,  0, 11,  0,  0,  0, 92,  0,  0,  0, 92,  0,  0,  0,
 92,  0,  0,  0, 92,  0,  0,  0, 93,  0,  0,  0, 93,  0,  0,  0, 93,  0,  0,  0,
 93,  0,  0,  0, 93,  0,  0,  0, 94,  0,  0,  0, 95,  0,  0,  0,  1,  0,  0,  0,
  6,  0,  0,  0, 99,104,117,110,107,  0,  4,  0,  0,  0, 10,  0,  0,  0,  1,  0,
  0,  0,  7,  0,  0,  0,104, 97,110,100,108,101,  0, 14,  0,  0,  0, 90,  0,  0,
  0, 90,  0,  0,  0, 95,  0,  0,  0, 95,  0,  0,  0, 95,  0,  0,  0, 95,  0,  0,
  0, 96,  0,  0,  0, 96,  0,  0,  0, 96,  0,  0,  0, 96,  0,  0,  0, 96,  0,  0,
  0, 96,  0,  0,  0, 96,  0,  0,  0, 97,  0,  0,  0,  2,  0,  0,  0,  7,  0,  0,
  0,104, 97,110,100,108,101,  0,  0,  0,  0,  0, 13,  0,  0,  0,  7,  0,  0,  0,
105,111, 95,101,114,114,  0,  0,  0,  0,  0, 13,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,100,  0,  0,  0,108,  0,  0,  0,  1,  1,  0,  3,  8,  0,  0,  0, 68,
  0,  0,  0, 70,  0,192,  0,128,  0,  0,  0, 92, 64,  0,  1,100,  0,  0,  0,  0,
  0,  0,  0, 94,  0,  0,  1, 30,  0,128,  0,  1,  0,  0,  0,  4,  7,  0,  0,  0,
 97,115,115,101,114,116,  0,  1,  0,  0,  0,  0,  0,  0,  0,102,  0,  0,  0,107,
  0,  0,  0,  1,  0,  0,  4, 14,  0,  0,  0,  4,  0,  0,  0, 28,192,128,  0,155,
 64,128,  0, 22,  0,  0,128,132,  0,  0,  0,136,  0,  0,  0, 26, 64,  0,  0, 22,
192,  0,128,131,  0,  0,  1,192,  0,128,  0,158,  0,128,  1, 22,  0,  0,128, 30,
  0,  0,  1, 30,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  0,  0,  0,103,
  0,  0,  0,103,  0,  0,  0,104,  0,  0,  0,104,  0,  0,  0,104,  0,  0,  0,104,
  0,  0,  0,105,  0,  0,  0,105,  0,  0,  0,105,  0,  0,  0,105,  0,  0,  0,105,
  0,  0,  0,105,  0,  0,  0,106,  0,  0,  0,107,  0,  0,  0,  2,  0,  0,  0,  6,
  0,  0,  0, 99,104,117,110,107,  0,  2,  0,  0,  0, 13,  0,  0,  0, 11,  0,  0,
  0,101,114,114, 95,111,114, 95,110,101,119,  0,  2,  0,  0,  0, 13,  0,  0,  0,
  1,  0,  0,  0,  4,  0,  0,  0,115,114, 99,  0,  8,  0,  0,  0,101,  0,  0,  0,
101,  0,  0,  0,101,  0,  0,  0,101,  0,  0,  0,107,  0,  0,  0,107,  0,  0,  0,
107,  0,  0,  0,108,  0,  0,  0,  1,  0,  0,  0,  4,  0,  0,  0,115,114, 99,  0,
  0,  0,  0,  0,  7,  0,  0,  0,  1,  0,  0,  0,  5,  0,  0,  0, 98, 97,115,101,
  0,  0,  0,  0,  0,111,  0,  0,  0,121,  0,  0,  0,  1,  1,  0,  3, 15,  0,  0,
  0, 26,  0,  0,  0, 22,192,  1,128, 65,  0,  0,  0,164,  0,  0,  0,  4,  0,  0,
  0,  0,  0,  0,  0,  0,  0,128,  0,158,  0,  0,  1, 99,  0,  0,  0, 22,192,  0,
128, 69, 64,  0,  0, 70,128,192,  0, 93,  0,128,  0, 94,  0,  0,  0, 30,  0,128,
  0,  3,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,240, 63,  4,  7,  0,  0,  0,115,
111,117,114, 99,101,  0,  4,  6,  0,  0,  0,101,109,112,116,121,  0,  1,  0,  0,
  0,  0,  0,  0,  0,114,  0,  0,  0,119,  0,  0,  0,  3,  0,  0,  5, 20,  0,  0,
  0,  4,  0,  0,  0,  6,  0, 64,  0, 68,  0,128,  0,132,  0,  0,  1,196,  0,  0,
  1,  5, 65,  0,  0,204,  0,129,  1,205,128,192,  1, 28,128,  0,  2, 68,  0,  0,
  1,133, 64,  0,  0, 76,128,128,  0, 72,  0,  0,  1, 87,192, 64,  0, 22, 64,  0,
128, 30,  0,  0,  1, 22, 64,  0,128, 67,  0,128,  0, 94,  0,  0,  1, 30,  0,128,
  0,  4,  0,  0,  0,  4,  4,  0,  0,  0,115,117, 98,  0,  4, 10,  0,  0,  0, 66,
 76, 79, 67, 75, 83, 73, 90, 69,  0,  3,  0,  0,  0,  0,  0,  0,240, 63,  4,  1,
  0,  0,  0,  0,  0,  0,  0,  0, 20,  0,  0,  0,115,  0,  0,  0,115,  0,  0,  0,
115,  0,  0,  0,115,  0,  0,  0,115,  0,  0,  0,115,  0,  0,  0,115,  0,  0,  0,
115,  0,  0,  0,115,  0,  0,  0,116,  0,  0,  0,116,  0,  0,  0,116,  0,  0,  0,
116,  0,  0,  0,117,  0,  0,  0,117,  0,  0,  0,117,  0,  0,  0,117,  0,  0,  0,
118,  0,  0,  0,118,  0,  0,  0,119,  0,  0,  0,  1,  0,  0,  0,  6,  0,  0,  0,
 99,104,117,110,107,  0,  9,  0,  0,  0, 19,  0,  0,  0,  3,  0,  0,  0,  7,  0,
  0,  0,115,116,114,105,110,103,  0,  2,  0,  0,  0,115,  0,  2,  0,  0,  0,105,
  0, 15,  0,  0,  0,112,  0,  0,  0,112,  0,  0,  0,113,  0,  0,  0,119,  0,  0,
  0,119,  0,  0,  0,119,  0,  0,  0,119,  0,  0,  0,119,  0,  0,  0,119,  0,  0,
  0,119,  0,  0,  0,120,  0,  0,  0,120,  0,  0,  0,120,  0,  0,  0,120,  0,  0,
  0,121,  0,  0,  0,  2,  0,  0,  0,  2,  0,  0,  0,115,  0,  0,  0,  0,  0, 14,
  0,  0,  0,  2,  0,  0,  0,105,  0,  3,  0,  0,  0,  8,  0,  0,  0,  1,  0,  0,
  0,  7,  0,  0,  0,115,116,114,105,110,103,  0,  0,  0,  0,  0,124,  0,  0,  0,
136,  0,  0,  0,  2,  1,  0,  3, 11,  0,  0,  0, 68,  0,  0,  0, 70,  0,192,  0,
128,  0,  0,  0, 92, 64,  0,  1, 74,  0,  0,  0,164,  0,  0,  0,  4,  0,128,  0,
  0,  0,128,  0,  0,  0,  0,  0,158,  0,  0,  1, 30,  0,128,  0,  1,  0,  0,  0,
  4,  7,  0,  0,  0, 97,115,115,101,114,116,  0,  1,  0,  0,  0,  0,  0,  0,  0,
127,  0,  0,  0,135,  0,  0,  0,  3,  1,  0,  4, 21,  0,  0,  0, 26, 64,  0,  0,
 22,  0,  3,128, 68,  0,  0,  0, 70,  0,192,  0,132,  0,128,  0, 92,128,  0,  1,
  0,  0,128,  0, 26, 64,  0,  0, 22,192,  0,128, 68,  0,  0,  1, 93,  0,128,  0,
 94,  0,  0,  0, 22,128,  1,128, 30,  0,  0,  1, 22,  0,  1,128, 68,  0,  0,  0,
 70, 64,192,  0,132,  0,128,  0,192,  0,  0,  0, 92, 64,128,  1, 30,  0,128,  0,
  2,  0,  0,  0,  4,  7,  0,  0,  0,114,101,109,111,118,101,  0,  4,  7,  0,  0,
  0,105,110,115,101,114,116,  0,  0,  0,  0,  0, 21,  0,  0,  0,128,  0,  0,  0,
128,  0,  0,  0,129,  0,  0,  0,129,  0,  0,  0,129,  0,  0,  0,129,  0,  0,  0,
129,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,130,  0,  0,  0,
130,  0,  0,  0,130,  0,  0,  0,131,  0,  0,  0,131,  0,  0,  0,133,  0,  0,  0,
133,  0,  0,  0,133,  0,  0,  0,133,  0,  0,  0,133,  0,  0,  0,135,  0,  0,  0,
  1,  0,  0,  0,  6,  0,  0,  0, 99,104,117,110,107,  0,  0,  0,  0,  0, 20,  0,
  0,  0,  3,  0,  0,  0,  6,  0,  0,  0,116, 97, 98,108,101,  0,  2,  0,  0,  0,
116,  0,  4,  0,  0,  0,115,114, 99,  0, 11,  0,  0,  0,125,  0,  0,  0,125,  0,
  0,  0,125,  0,  0,  0,125,  0,  0,  0,126,  0,  0,  0,135,  0,  0,  0,135,  0,
  0,  0,135,  0,  0,  0,135,  0,  0,  0,135,  0,  0,  0,136,  0,  0,  0,  2,  0,
  0,  0,  4,  0,  0,  0,115,114, 99,  0,  0,  0,  0,  0, 10,  0,  0,  0,  2,  0,
  0,  0,116,  0,  5,  0,  0,  0, 10,  0,  0,  0,  2,  0,  0,  0,  5,  0,  0,  0,
 98, 97,115,101,  0,  6,  0,  0,  0,116, 97, 98,108,101,  0,  0,  0,  0,  0,138,
  0,  0,  0,183,  0,  0,  0,  1,  2,  0,  7, 20,  0,  0,  0,132,  0,  0,  0,134,
  0, 64,  1,219,  0,  0,  0, 22,  0,  0,128,192,  0,128,  0,156, 64,  0,  1,129,
 64,  0,  0,193, 64,  0,  0,  1,129,  0,  0, 67,  1,128,  2,164,  1,  0,  0,  0,
  0,128,  1,  4,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  1,  0,  0,128,  2,  0,
  0,  0,  0,  0,  0,128,  0,158,  1,  0,  1, 30,  0,128,  0,  3,  0,  0,  0,  4,
  7,  0,  0,  0, 97,115,115,101,114,116,  0,  4,  1,  0,  0,  0,  0,  4,  8,  0,
  0,  0,102,101,101,100,105,110,103,  0,  1,  0,  0,  0,  0,  0,  0,  0,143,  0,
  0,  0,182,  0,  0,  0,  7,  0,  0,  3, 88,  0,  0,  0,  4,  0,  0,  0, 26, 64,
  0,  0, 22,  0,  1,128,  4,  0,128,  0,  6,  0, 64,  0, 65, 64,  0,  0,129,128,
  0,  0, 28, 64,128,  1,  4,  0,  0,  1, 23,192, 64,  0, 22,  0, 10,128,  4,  0,
128,  2, 28,192,128,  0, 72,  0,  0,  2,  8,  0,128,  1,  4,  0,  0,  2, 26,  0,
  0,  0, 22,128,  0,128,  3,  0,  0,  0, 68,  0,  0,  2, 30,  0,128,  1,  4,  0,
  0,  3, 68,  0,128,  1, 28,128,  0,  1,  8,  0,  0,  0,  4,  0,  0,  0, 26, 64,
  0,  0, 22,128,  2,128,  4,  0,128,  1, 26,  0,  0,  0, 22,  0,  1,128,  4,  0,
128,  0,  6,  0, 64,  0, 65,  0,  1,  0, 28, 64,  0,  1, 22,192,248,127,  3,  0,
  0,  0, 30,  0,  0,  1, 22,  0,248,127,  4,  0,  0,  0, 87, 64, 65,  0, 22, 64,
247,127,  1,128,  1,  0,  8,  0,  0,  1,  4,  0,128,  1, 26,  0,  0,  0, 22, 64,
  0,128,  1, 64,  1,  0,  8,  0,128,  1,  4,  0,  0,  0, 30,  0,  0,  1, 22,192,
244,127,  4,  0,  0,  3, 68,  0,128,  1, 28,128,  0,  1,  8,  0,  0,  0,  4,  0,
  0,  0, 23, 64, 65,  0, 22,128,  2,128,  4,  0,128,  1, 23, 64, 65,  0, 22,128,
  0,128,  1,192,  0,  0,  8,  0,  0,  1, 22,128,241,127,  4,  0,128,  0,  6,  0,
 64,  0, 65,192,  1,  0, 28, 64,  0,  1, 22, 64,240,127,  4,  0,  0,  0, 26, 64,
  0,  0, 22,128,  2,128,  4,  0,128,  1, 26,  0,  0,  0, 22,  0,  1,128,  4,  0,
128,  0,  6,  0, 64,  0, 65,  0,  1,  0, 28, 64,  0,  1, 22,128,237,127,  3,  0,
  0,  0, 30,  0,  0,  1, 22,192,236,127,  4,  0,  0,  0, 30,  0,  0,  1, 22,  0,
236,127, 30,  0,128,  0,  8,  0,  0,  0,  4,  6,  0,  0,  0,101,114,114,111,114,
  0,  4, 17,  0,  0,  0,115,111,117,114, 99,101, 32,105,115, 32,101,109,112,116,
121, 33,  0,  3,  0,  0,  0,  0,  0,  0,  0, 64,  4,  8,  0,  0,  0,102,101,101,
100,105,110,103,  0,  4, 34,  0,  0,  0,102,105,108,116,101,114, 32,114,101,116,
117,114,110,101,100, 32,105,110, 97,112,112,114,111,112,114,105, 97,116,101, 32,
110,105,108,  0,  4,  1,  0,  0,  0,  0,  4,  7,  0,  0,  0,101, 97,116,105,110,
103,  0,  4, 19,  0,  0,  0,102,105,108,116,101,114, 32,114,101,116,117,114,110,
101,100, 32, 34, 34,  0,  0,  0,  0,  0, 88,  0,  0,  0,144,  0,  0,  0,144,  0,
  0,  0,144,  0,  0,  0,145,  0,  0,  0,145,  0,  0,  0,145,  0,  0,  0,145,  0,
  0,  0,145,  0,  0,  0,148,  0,  0,  0,148,  0,  0,  0,148,  0,  0,  0,149,  0,
  0,  0,149,  0,  0,  0,149,  0,  0,  0,149,  0,  0,  0,150,  0,  0,  0,150,  0,
  0,  0,150,  0,  0,  0,150,  0,  0,  0,150,  0,  0,  0,150,  0,  0,  0,151,  0,
  0,  0,151,  0,  0,  0,151,  0,  0,  0,151,  0,  0,  0,152,  0,  0,  0,152,  0,
  0,  0,152,  0,  0,  0,153,  0,  0,  0,153,  0,  0,  0,153,  0,  0,  0,154,  0,
  0,  0,154,  0,  0,  0,154,  0,  0,  0,154,  0,  0,  0,154,  0,  0,  0,156,  0,
  0,  0,156,  0,  0,  0,157,  0,  0,  0,158,  0,  0,  0,158,  0,  0,  0,158,  0,
  0,  0,159,  0,  0,  0,159,  0,  0,  0,160,  0,  0,  0,160,  0,  0,  0,160,  0,
  0,  0,160,  0,  0,  0,160,  0,  0,  0,161,  0,  0,  0,161,  0,  0,  0,162,  0,
  0,  0,164,  0,  0,  0,164,  0,  0,  0,164,  0,  0,  0,164,  0,  0,  0,165,  0,
  0,  0,165,  0,  0,  0,165,  0,  0,  0,166,  0,  0,  0,166,  0,  0,  0,166,  0,
  0,  0,167,  0,  0,  0,167,  0,  0,  0,167,  0,  0,  0,169,  0,  0,  0,169,  0,
  0,  0,169,  0,  0,  0,169,  0,  0,  0,170,  0,  0,  0,171,  0,  0,  0,171,  0,
  0,  0,171,  0,  0,  0,172,  0,  0,  0,172,  0,  0,  0,172,  0,  0,  0,173,  0,
  0,  0,173,  0,  0,  0,173,  0,  0,  0,173,  0,  0,  0,173,  0,  0,  0,175,  0,
  0,  0,175,  0,  0,  0,176,  0,  0,  0,178,  0,  0,  0,178,  0,  0,  0,180,  0,
  0,  0,182,  0,  0,  0,  0,  0,  0,  0,  7,  0,  0,  0,  9,  0,  0,  0,108, 97,
115,116, 95,111,117,116,  0,  5,  0,  0,  0, 98, 97,115,101,  0,  6,  0,  0,  0,
115,116, 97,116,101,  0,  8,  0,  0,  0,108, 97,115,116, 95,105,110,  0,  4,  0,
  0,  0,101,114,114,  0,  4,  0,  0,  0,115,114, 99,  0,  2,  0,  0,  0,102,  0,
 20,  0,  0,  0,139,  0,  0,  0,139,  0,  0,  0,139,  0,  0,  0,139,  0,  0,  0,
139,  0,  0,  0,139,  0,  0,  0,140,  0,  0,  0,140,  0,  0,  0,141,  0,  0,  0,
142,  0,  0,  0,182,  0,  0,  0,182,  0,  0,  0,182,  0,  0,  0,182,  0,  0,  0,
182,  0,  0,  0,182,  0,  0,  0,182,  0,  0,  0,182,  0,  0,  0,182,  0,  0,  0,
183,  0,  0,  0,  6,  0,  0,  0,  4,  0,  0,  0,115,114, 99,  0,  0,  0,  0,  0,
 19,  0,  0,  0,  2,  0,  0,  0,102,  0,  0,  0,  0,  0, 19,  0,  0,  0,  8,  0,
  0,  0,108, 97,115,116, 95,105,110,  0,  8,  0,  0,  0, 19,  0,  0,  0,  9,  0,
  0,  0,108, 97,115,116, 95,111,117,116,  0,  8,  0,  0,  0, 19,  0,  0,  0,  6,
  0,  0,  0,115,116, 97,116,101,  0,  9,  0,  0,  0, 19,  0,  0,  0,  4,  0,  0,
  0,101,114,114,  0, 10,  0,  0,  0, 19,  0,  0,  0,  1,  0,  0,  0,  5,  0,  0,
  0, 98, 97,115,101,  0,  0,  0,  0,  0,188,  0,  0,  0,198,  0,  0,  0,  1,  0,
  7,  4, 11,  0,  0,  0, 68,  0,  0,  0, 70,  0,192,  0,128,  0,  0,  0,193, 64,
  0,  0, 92,128,128,  1,164,  0,  0,  0,  0,  0,128,  0,  4,  0,  0,  0,  0,  0,
  0,  0,158,  0,  0,  1, 30,  0,128,  0,  2,  0,  0,  0,  4,  7,  0,  0,  0,114,
101,109,111,118,101,  0,  3,  0,  0,  0,  0,  0,  0,240, 63,  1,  0,  0,  0,  0,
  0,  0,  0,190,  0,  0,  0,197,  0,  0,  0,  3,  0,  0,  5, 21,  0,  0,  0,  4,
  0,  0,  0, 26,  0,  0,  0, 22,  0,  4,128,  4,  0,  0,  0, 28,192,128,  0, 26,
  0,  0,  0, 22,  0,  0,128, 30,  0,  0,  1, 90,  0,  0,  0, 22,128,  0,128,131,
  0,  0,  1,192,  0,128,  0,158,  0,128,  1,132,  0,128,  0,134,  0, 64,  1,196,
  0,  0,  1,  1, 65,  0,  0,156,128,128,  1,136,  0,  0,  0, 22,192,250,127, 30,
  0,128,  0,  2,  0,  0,  0,  4,  7,  0,  0,  0,114,101,109,111,118,101,  0,  3,
  0,  0,  0,  0,  0,  0,240, 63,  0,  0,  0,  0, 21,  0,  0,  0,191,  0,  0,  0,
191,  0,  0,  0,191,  0,  0,  0,192,  0,  0,  0,192,  0,  0,  0,193,  0,  0,  0,
193,  0,  0,  0,193,  0,  0,  0,194,  0,  0,  0,194,  0,  0,  0,194,  0,  0,  0,
194,  0,  0,  0,194,  0,  0,  0,195,  0,  0,  0,195,  0,  0,  0,195,  0,  0,  0,
195,  0,  0,  0,195,  0,  0,  0,195,  0,  0,  0,195,  0,  0,  0,197,  0,  0,  0,
  2,  0,  0,  0,  6,  0,  0,  0, 99,104,117,110,107,  0,  5,  0,  0,  0, 19,  0,
  0,  0,  4,  0,  0,  0,101,114,114,  0,  5,  0,  0,  0, 19,  0,  0,  0,  3,  0,
  0,  0,  4,  0,  0,  0,115,114, 99,  0,  6,  0,  0,  0,116, 97, 98,108,101,  0,
  4,  0,  0,  0, 97,114,103,  0, 11,  0,  0,  0,189,  0,  0,  0,189,  0,  0,  0,
189,  0,  0,  0,189,  0,  0,  0,189,  0,  0,  0,197,  0,  0,  0,197,  0,  0,  0,
197,  0,  0,  0,197,  0,  0,  0,197,  0,  0,  0,198,  0,  0,  0,  2,  0,  0,  0,
  4,  0,  0,  0, 97,114,103,  0,  0,  0,  0,  0, 10,  0,  0,  0,  4,  0,  0,  0,
115,114, 99,  0,  5,  0,  0,  0, 10,  0,  0,  0,  1,  0,  0,  0,  6,  0,  0,  0,
116, 97, 98,108,101,  0,  0,  0,  0,  0,204,  0,  0,  0,211,  0,  0,  0,  1,  1,
  0,  4, 11,  0,  0,  0, 26, 64,  0,  0, 22, 64,  0,128, 74,  0,  0,  0,  0,  0,
128,  0,100,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,128,  0,128,  0,192,  0,
  0,  0,158,  0,128,  1, 30,  0,128,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,
  0,  0,206,  0,  0,  0,209,  0,  0,  0,  2,  2,  0,  5, 10,  0,  0,  0, 26,  0,
  0,  0, 22,  0,  1,128,132,  0,  0,  0,134,  0, 64,  1,196,  0,128,  0,  0,  1,
  0,  0,156, 64,128,  1,129, 64,  0,  0,158,  0,  0,  1, 30,  0,128,  0,  2,  0,
  0,  0,  4,  7,  0,  0,  0,105,110,115,101,114,116,  0,  3,  0,  0,  0,  0,  0,
  0,240, 63,  0,  0,  0,  0, 10,  0,  0,  0,207,  0,  0,  0,207,  0,  0,  0,207,
  0,  0,  0,207,  0,  0,  0,207,  0,  0,  0,207,  0,  0,  0,207,  0,  0,  0,208,
  0,  0,  0,208,  0,  0,  0,209,  0,  0,  0,  2,  0,  0,  0,  6,  0,  0,  0, 99,
104,117,110,107,  0,  0,  0,  0,  0,  9,  0,  0,  0,  4,  0,  0,  0,101,114,114,
  0,  0,  0,  0,  0,  9,  0,  0,  0,  2,  0,  0,  0,  6,  0,  0,  0,116, 97, 98,
108,101,  0,  2,  0,  0,  0,116,  0, 11,  0,  0,  0,205,  0,  0,  0,205,  0,  0,
  0,205,  0,  0,  0,205,  0,  0,  0,209,  0,  0,  0,209,  0,  0,  0,209,  0,  0,
  0,210,  0,  0,  0,210,  0,  0,  0,210,  0,  0,  0,211,  0,  0,  0,  2,  0,  0,
  0,  2,  0,  0,  0,116,  0,  0,  0,  0,  0, 10,  0,  0,  0,  2,  0,  0,  0,102,
  0,  7,  0,  0,  0, 10,  0,  0,  0,  1,  0,  0,  0,  6,  0,  0,  0,116, 97, 98,
108,101,  0,  0,  0,  0,  0,214,  0,  0,  0,222,  0,  0,  0,  1,  1,  0,  3,  8,
  0,  0,  0, 68,  0,  0,  0, 70,  0,192,  0,128,  0,  0,  0, 92, 64,  0,  1,100,
  0,  0,  0,  0,  0,  0,  0, 94,  0,  0,  1, 30,  0,128,  0,  1,  0,  0,  0,  4,
  7,  0,  0,  0, 97,115,115,101,114,116,  0,  1,  0,  0,  0,  0,  0,  0,  0,216,
  0,  0,  0,221,  0,  0,  0,  1,  2,  0,  6, 16,  0,  0,  0,132,  0,  0,  0,192,
  0,  0,  0,  0,  1,128,  0,156,192,128,  1,154, 64,  0,  0, 22,128,  0,128,  3,
  1,  0,  2, 64,  1,128,  1, 30,  1,128,  1, 27, 65,128,  1, 22,  0,  0,128,  4,
  1,  0,  0,  8,  1,  0,  0,  1,  1,  0,  0, 30,  1,  0,  1, 30,  0,128,  0,  1,
  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,240, 63,  0,  0,  0,  0, 16,  0,  0,  0,
217,  0,  0,  0,217,  0,  0,  0,217,  0,  0,  0,217,  0,  0,  0,218,  0,  0,  0,
218,  0,  0,  0,218,  0,  0,  0,218,  0,  0,  0,218,  0,  0,  0,219,  0,  0,  0,
219,  0,  0,  0,219,  0,  0,  0,219,  0,  0,  0,220,  0,  0,  0,220,  0,  0,  0,
221,  0,  0,  0,  4,  0,  0,  0,  6,  0,  0,  0, 99,104,117,110,107,  0,  0,  0,
  0,  0, 15,  0,  0,  0,  4,  0,  0,  0,101,114,114,  0,  0,  0,  0,  0, 15,  0,
  0,  0,  4,  0,  0,  0,114,101,116,  0,  4,  0,  0,  0, 15,  0,  0,  0, 11,  0,
  0,  0,101,114,114, 95,111,114, 95,110,101,119,  0,  4,  0,  0,  0, 15,  0,  0,
  0,  1,  0,  0,  0,  4,  0,  0,  0,115,110,107,  0,  8,  0,  0,  0,215,  0,  0,
  0,215,  0,  0,  0,215,  0,  0,  0,215,  0,  0,  0,221,  0,  0,  0,221,  0,  0,
  0,221,  0,  0,  0,222,  0,  0,  0,  1,  0,  0,  0,  4,  0,  0,  0,115,110,107,
  0,  0,  0,  0,  0,  7,  0,  0,  0,  1,  0,  0,  0,  5,  0,  0,  0, 98, 97,115,
101,  0,  0,  0,  0,  0,225,  0,  0,  0,234,  0,  0,  0,  0,  2,  0,  4, 14,  0,
  0,  0, 26,  0,  0,  0, 22,192,  0,128,164,  0,  0,  0,  0,  0,  0,  0,158,  0,
  0,  1, 22,128,  1,128,133,  0,  0,  0,134, 64, 64,  1,219, 64,128,  0, 22,  0,
  0,128,193,128,  0,  0,157,  0,  0,  1,158,  0,  0,  0, 30,  0,128,  0,  3,  0,
  0,  0,  4,  5,  0,  0,  0,115,105,110,107,  0,  4,  6,  0,  0,  0,101,114,114,
111,114,  0,  4, 20,  0,  0,  0,117,110, 97, 98,108,101, 32,116,111, 32,111,112,
101,110, 32,102,105,108,101,  0,  1,  0,  0,  0,  0,  0,  0,  0,227,  0,  0,  0,
232,  0,  0,  0,  1,  2,  0,  5, 14,  0,  0,  0, 26, 64,  0,  0, 22, 64,  1,128,
132,  0,  0,  0,139,  0, 64,  1,156, 64,  0,  1,129, 64,  0,  0,158,  0,  0,  1,
 22,  0,  1,128,132,  0,  0,  0,139,128, 64,  1,  0,  1,  0,  0,157,  0,128,  1,
158,  0,  0,  0, 30,  0,128,  0,  3,  0,  0,  0,  4,  6,  0,  0,  0, 99,108,111,
115,101,  0,  3,  0,  0,  0,  0,  0,  0,240, 63,  4,  6,  0,  0,  0,119,114,105,
116,101,  0,  0,  0,  0,  0, 14,  0,  0,  0,228,  0,  0,  0,228,  0,  0,  0,229,
  0,  0,  0,229,  0,  0,  0,229,  0,  0,  0,230,  0,  0,  0,230,  0,  0,  0,230,
  0,  0,  0,231,  0,  0,  0,231,  0,  0,  0,231,  0,  0,  0,231,  0,  0,  0,231,
  0,  0,  0,232,  0,  0,  0,  2,  0,  0,  0,  6,  0,  0,  0, 99,104,117,110,107,
  0,  0,  0,  0,  0, 13,  0,  0,  0,  4,  0,  0,  0,101,114,114,  0,  0,  0,  0,
  0, 13,  0,  0,  0,  1,  0,  0,  0,  7,  0,  0,  0,104, 97,110,100,108,101,  0,
 14,  0,  0,  0,226,  0,  0,  0,226,  0,  0,  0,232,  0,  0,  0,232,  0,  0,  0,
232,  0,  0,  0,232,  0,  0,  0,233,  0,  0,  0,233,  0,  0,  0,233,  0,  0,  0,
233,  0,  0,  0,233,  0,  0,  0,233,  0,  0,  0,233,  0,  0,  0,234,  0,  0,  0,
  2,  0,  0,  0,  7,  0,  0,  0,104, 97,110,100,108,101,  0,  0,  0,  0,  0, 13,
  0,  0,  0,  7,  0,  0,  0,105,111, 95,101,114,114,  0,  0,  0,  0,  0, 13,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,237,  0,  0,  0,239,  0,  0,  0,  0,  0,
  0,  2,  3,  0,  0,  0,  1,  0,  0,  0, 30,  0,  0,  1, 30,  0,128,  0,  1,  0,
  0,  0,  3,  0,  0,  0,  0,  0,  0,240, 63,  0,  0,  0,  0,  3,  0,  0,  0,238,
  0,  0,  0,238,  0,  0,  0,239,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,241,  0,  0,  0,243,  0,  0,  0,  1,  0,  0,  2,  3,  0,  0,  0,  4,
  0,  0,  0, 30,  0,  0,  1, 30,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,
  0,  0,  0,242,  0,  0,  0,242,  0,  0,  0,243,  0,  0,  0,  0,  0,  0,  0,  1,
  0,  0,  0,  5,  0,  0,  0,110,117,108,108,  0,  0,  0,  0,  0,246,  0,  0,  0,
250,  0,  0,  0,  0,  1,  0,  2,  4,  0,  0,  0,100,  0,  0,  0,  0,  0,  0,  0,
 94,  0,  0,  1, 30,  0,128,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,
247,  0,  0,  0,249,  0,  0,  0,  1,  0,  0,  2,  3,  0,  0,  0, 68,  0,  0,  0,
 30,  0,128,  1, 30,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,
248,  0,  0,  0,248,  0,  0,  0,249,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,
  4,  0,  0,  0,101,114,114,  0,  4,  0,  0,  0,249,  0,  0,  0,249,  0,  0,  0,
249,  0,  0,  0,250,  0,  0,  0,  1,  0,  0,  0,  4,  0,  0,  0,101,114,114,  0,
  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,253,  0,  0,  0,
 11,  1,  0,  0,  1,  2,  0,  4, 11,  0,  0,  0,132,  0,  0,  0,134,  0, 64,  1,
219,  0,  0,  0, 22,  0,  0,128,192,  0,128,  0,156, 64,  0,  1,164,  0,  0,  0,
  0,  0,  0,  0,  0,  0,128,  0,158,  0,  0,  1, 30,  0,128,  0,  1,  0,  0,  0,
  4,  7,  0,  0,  0, 97,115,115,101,114,116,  0,  1,  0,  0,  0,  0,  0,  0,  0,
255,  0,  0,  0, 10,  1,  0,  0,  2,  2,  0,  8, 30,  0,  0,  0, 87,  0, 64,  0,
 22,  0,  6,128,132,  0,  0,  0,192,  0,  0,  0,156,128,  0,  1,219,  0,  0,  0,
 22,  0,  0,128,193,  0,  0,  0,  4,  1,128,  0, 64,  1,  0,  1,128,  1,128,  0,
 28,193,128,  1, 26, 65,  0,  0, 22,128,  0,128,131,  1,  0,  3,192,  1,128,  2,
158,  1,128,  1, 23,192,  0,  1, 22, 64,  0,128,129, 65,  0,  0,158,  1,  0,  1,
132,  1,  0,  0,192,  1,128,  1,156,129,  0,  1,128,  0,  0,  3, 22, 64,251,127,
 22, 64,  0,128,129, 64,  0,  0,158,  0,  0,  1, 30,  0,128,  0,  2,  0,  0,  0,
  4,  1,  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,240, 63,  0,  0,  0,  0, 30,
  0,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0,  1,  1,  0,  0,  1,  1,  0,  0,  1,
  1,  0,  0,  2,  1,  0,  0,  2,  1,  0,  0,  2,  1,  0,  0,  4,  1,  0,  0,  4,
  1,  0,  0,  4,  1,  0,  0,  4,  1,  0,  0,  5,  1,  0,  0,  5,  1,  0,  0,  5,
  1,  0,  0,  5,  1,  0,  0,  5,  1,  0,  0,  6,  1,  0,  0,  6,  1,  0,  0,  6,
  1,  0,  0,  6,  1,  0,  0,  7,  1,  0,  0,  7,  1,  0,  0,  7,  1,  0,  0,  7,
  1,  0,  0,  7,  1,  0,  0,  8,  1,  0,  0,  9,  1,  0,  0,  9,  1,  0,  0, 10,
  1,  0,  0,  6,  0,  0,  0,  6,  0,  0,  0, 99,104,117,110,107,  0,  0,  0,  0,
  0, 29,  0,  0,  0,  4,  0,  0,  0,101,114,114,  0,  0,  0,  0,  0, 29,  0,  0,
  0,  9,  0,  0,  0,102,105,108,116,101,114,101,100,  0,  5,  0,  0,  0, 26,  0,
  0,  0,  5,  0,  0,  0,100,111,110,101,  0,  8,  0,  0,  0, 26,  0,  0,  0,  4,
  0,  0,  0,114,101,116,  0, 12,  0,  0,  0, 25,  0,  0,  0,  7,  0,  0,  0,115,
110,107,101,114,114,  0, 12,  0,  0,  0, 25,  0,  0,  0,  2,  0,  0,  0,  2,  0,
  0,  0,102,  0,  4,  0,  0,  0,115,110,107,  0, 11,  0,  0,  0,254,  0,  0,  0,
254,  0,  0,  0,254,  0,  0,  0,254,  0,  0,  0,254,  0,  0,  0,254,  0,  0,  0,
 10,  1,  0,  0, 10,  1,  0,  0, 10,  1,  0,  0, 10,  1,  0,  0, 11,  1,  0,  0,
  2,  0,  0,  0,  2,  0,  0,  0,102,  0,  0,  0,  0,  0, 10,  0,  0,  0,  4,  0,
  0,  0,115,110,107,  0,  0,  0,  0,  0, 10,  0,  0,  0,  1,  0,  0,  0,  5,  0,
  0,  0, 98, 97,115,101,  0,  0,  0,  0,  0, 17,  1,  0,  0, 22,  1,  0,  0,  0,
  2,  0,  8, 19,  0,  0,  0,128,  0,  0,  0,156,192,128,  0,  0,  1,128,  0, 64,
  1,  0,  1,128,  1,128,  1, 28,193,128,  1,154,  0,  0,  0, 22,  0,  1,128, 26,
  1,  0,  0, 22,128,  0,128,129,  1,  0,  0,158,  1,  0,  1, 22,  0,  1,128,131,
  1,  0,  3,219, 65,128,  1, 22,  0,  0,128,192,  1,128,  2,158,  1,128,  1, 30,
  0,128,  0,  1,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,240, 63,  0,  0,  0,  0,
 19,  0,  0,  0, 18,  1,  0,  0, 18,  1,  0,  0, 19,  1,  0,  0, 19,  1,  0,  0,
 19,  1,  0,  0, 19,  1,  0,  0, 20,  1,  0,  0, 20,  1,  0,  0, 20,  1,  0,  0,
 20,  1,  0,  0, 20,  1,  0,  0, 20,  1,  0,  0, 20,  1,  0,  0, 21,  1,  0,  0,
 21,  1,  0,  0, 21,  1,  0,  0, 21,  1,  0,  0, 21,  1,  0,  0, 22,  1,  0,  0,
  6,  0,  0,  0,  4,  0,  0,  0,115,114, 99,  0,  0,  0,  0,  0, 18,  0,  0,  0,
  4,  0,  0,  0,115,110,107,  0,  0,  0,  0,  0, 18,  0,  0,  0,  6,  0,  0,  0,
 99,104,117,110,107,  0,  2,  0,  0,  0, 18,  0,  0,  0,  8,  0,  0,  0,115,114,
 99, 95,101,114,114,  0,  2,  0,  0,  0, 18,  0,  0,  0,  4,  0,  0,  0,114,101,
116,  0,  6,  0,  0,  0, 18,  0,  0,  0,  8,  0,  0,  0,115,110,107, 95,101,114,
114,  0,  6,  0,  0,  0, 18,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  1,
  0,  0, 35,  1,  0,  0,  1,  3,  0,  7, 26,  0,  0,  0,196,  0,  0,  0,198,  0,
192,  1, 27,  1,  0,  0, 22,  0,  0,128,  0,  1,128,  0,220, 64,  0,  1,154, 64,
  0,  0, 22, 64,  0,128,197, 64,  0,  0,134,128,192,  1,192,  0,  0,  1,  0,  1,
  0,  0, 64,  1,128,  0,220,192,128,  1,218, 64,  0,  0, 22, 64,254,127, 26,  1,
  0,  0, 22,192,  0,128, 67,  1,128,  2,128,  1,  0,  2, 94,  1,128,  1, 22,192,
252,127, 65,193,  0,  0, 94,  1,  0,  1, 22,  0,252,127, 30,  0,128,  0,  4,  0,
  0,  0,  4,  7,  0,  0,  0, 97,115,115,101,114,116,  0,  4,  5,  0,  0,  0,112,
117,109,112,  0,  4,  5,  0,  0,  0,115,116,101,112,  0,  3,  0,  0,  0,  0,  0,
  0,240, 63,  0,  0,  0,  0, 26,  0,  0,  0, 26,  1,  0,  0, 26,  1,  0,  0, 26,
  1,  0,  0, 26,  1,  0,  0, 26,  1,  0,  0, 26,  1,  0,  0, 27,  1,  0,  0, 27,
  1,  0,  0, 27,  1,  0,  0, 27,  1,  0,  0, 29,  1,  0,  0, 29,  1,  0,  0, 29,
  1,  0,  0, 29,  1,  0,  0, 30,  1,  0,  0, 30,  1,  0,  0, 31,  1,  0,  0, 31,
  1,  0,  0, 31,  1,  0,  0, 31,  1,  0,  0, 31,  1,  0,  0, 31,  1,  0,  0, 32,
  1,  0,  0, 32,  1,  0,  0, 33,  1,  0,  0, 35,  1,  0,  0,  5,  0,  0,  0,  4,
  0,  0,  0,115,114, 99,  0,  0,  0,  0,  0, 25,  0,  0,  0,  4,  0,  0,  0,115,
110,107,  0,  0,  0,  0,  0, 25,  0,  0,  0,  5,  0,  0,  0,115,116,101,112,  0,
  0,  0,  0,  0, 25,  0,  0,  0,  4,  0,  0,  0,114,101,116,  0, 14,  0,  0,  0,
 24,  0,  0,  0,  4,  0,  0,  0,101,114,114,  0, 14,  0,  0,  0, 24,  0,  0,  0,
  1,  0,  0,  0,  5,  0,  0,  0, 98, 97,115,101,  0, 94,  0,  0,  0, 11,  0,  0,
  0, 11,  0,  0,  0, 11,  0,  0,  0, 12,  0,  0,  0, 12,  0,  0,  0, 12,  0,  0,
  0, 13,  0,  0,  0, 14,  0,  0,  0, 14,  0,  0,  0, 14,  0,  0,  0, 16,  0,  0,
  0, 16,  0,  0,  0, 17,  0,  0,  0, 17,  0,  0,  0, 18,  0,  0,  0, 18,  0,  0,
  0, 19,  0,  0,  0, 19,  0,  0,  0, 22,  0,  0,  0, 22,  0,  0,  0, 23,  0,  0,
  0, 23,  0,  0,  0, 29,  0,  0,  0, 36,  0,  0,  0, 36,  0,  0,  0, 29,  0,  0,
  0, 40,  0,  0,  0, 67,  0,  0,  0, 67,  0,  0,  0, 67,  0,  0,  0, 40,  0,  0,
  0, 75,  0,  0,  0, 77,  0,  0,  0, 79,  0,  0,  0, 79,  0,  0,  0, 77,  0,  0,
  0, 82,  0,  0,  0, 86,  0,  0,  0, 82,  0,  0,  0, 89,  0,  0,  0, 97,  0,  0,
  0, 89,  0,  0,  0,100,  0,  0,  0,108,  0,  0,  0,108,  0,  0,  0,100,  0,  0,
  0,111,  0,  0,  0,121,  0,  0,  0,121,  0,  0,  0,111,  0,  0,  0,124,  0,  0,
  0,136,  0,  0,  0,136,  0,  0,  0,136,  0,  0,  0,124,  0,  0,  0,138,  0,  0,
  0,183,  0,  0,  0,183,  0,  0,  0,138,  0,  0,  0,188,  0,  0,  0,198,  0,  0,
  0,198,  0,  0,  0,188,  0,  0,  0,204,  0,  0,  0,211,  0,  0,  0,211,  0,  0,
  0,204,  0,  0,  0,214,  0,  0,  0,222,  0,  0,  0,222,  0,  0,  0,214,  0,  0,
  0,225,  0,  0,  0,234,  0,  0,  0,225,  0,  0,  0,239,  0,  0,  0,241,  0,  0,
  0,243,  0,  0,  0,243,  0,  0,  0,241,  0,  0,  0,246,  0,  0,  0,250,  0,  0,
  0,246,  0,  0,  0,253,  0,  0,  0, 11,  1,  0,  0, 11,  1,  0,  0,253,  0,  0,
  0, 17,  1,  0,  0, 22,  1,  0,  0, 17,  1,  0,  0, 25,  1,  0,  0, 35,  1,  0,
  0, 35,  1,  0,  0, 25,  1,  0,  0, 35,  1,  0,  0,  5,  0,  0,  0,  7,  0,  0,
  0,115,116,114,105,110,103,  0,  3,  0,  0,  0, 93,  0,  0,  0,  6,  0,  0,  0,
116, 97, 98,108,101,  0,  6,  0,  0,  0, 93,  0,  0,  0,  5,  0,  0,  0, 98, 97,
115,101,  0,  7,  0,  0,  0, 93,  0,  0,  0,  6,  0,  0,  0,101,109,112,116,121,
  0, 32,  0,  0,  0, 93,  0,  0,  0,  5,  0,  0,  0,110,117,108,108,  0, 75,  0,
  0,  0, 93,  0,  0,  0,  0,  0,  0,  0,
};

LUAOPEN_API int luaopen_ltn12(lua_State *L) {
	int arg = lua_gettop(L);
	luaL_loadbuffer(L,(const char*)B1,sizeof(B1),"ltn12.lua");
	lua_insert(L,1);
	lua_call(L,arg,1);
	return 1;
}

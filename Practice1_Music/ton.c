
#define Ais1       121//262  /* Middle C */
#define H1         129//262  /* Middle C */

#define C1         17//262  /* Middle C */
#define Cis1       31//278
#define D1         43//294
#define Dis1       56//312
#define E1         67//330
#define F1         77//350
#define Fis1       87//370
#define G1         97//392
#define Gis1      106//416
#define A2        114//440
#define Ais2      122//467
//#define C_B_F  122//467
#define B2        130//495
#define H2        130//495
#define C2        137//523
#define Cis2      143//554
#define D2        150//588
#define Dis2      156//623
#define E2        161//660
#define F2        167//699
#define Fis2      171//741
#define G2        176//785
#define Gis2      180//830
#define A3        184//880
#define B3        192//880
#define C3        196//785
#define Cis3      199//554
#define D3        202//588

#define Fis3      213//741


#define Silence       0

#define AXEL_LAENGE 27
flash char AxelSong[AXEL_LAENGE][2] = {
  { Silence , 1 },
  { Fis2 , 4 },
  { A2 , 2}, 
  { Silence , 1 },
  { Fis2 , 2 },
  { Fis2 , 1 },
  { Ais2 , 2 },
  { Fis2 , 2 },
  { E2 , 2 },
  { Fis2 , 4 },
  { C3 , 2 },
  { Silence , 1 },
  { Fis2 , 2 },
  { Fis2 , 1 },
  { D3 , 2 },
  { Cis3 , 2 },
  { A2 , 2 },
  { Fis2 , 2 },
  { Cis3 , 2 },
  { Fis3 , 2 },
  { Fis2 , 1 },
  { E2 , 2},
  { E2 , 1 },
  { Cis2 , 2 },
  { Gis2 , 2 },
  { Fis2 , 4 },
  { Silence , 2 }
  };

#define BOND_LAENGE 38
flash char BondSong[BOND_LAENGE][2] = {
{ Silence , 2 },
{ C2 , 2 }, 
{ D2 , 1}, 
{ D2 , 1}, 
{ D2 , 2 }, 
{ D2 , 4}, 
{ C2 , 2 }, 
{ C2 , 2 }, 
{ C2 , 2 }, 
{ C2 , 2 }, 
{ Dis2 , 1}, 
{ Dis2 , 1}, 
{ Dis2 , 2 }, 
{ Dis2 , 4}, 
{ D2 , 2 }, 
{ D2 , 2 }, 
{ D2 , 2 }, 
{ C2 , 2 }, 
{ D2 , 1}, 
{ D2 , 1}, 
{ D2 , 2 }, 
{ D2 , 4}, 
{ C2 , 2 }, 
{ C2 , 2 }, 
{ C2 , 2 }, 
{ C2 , 2 }, 
{ Dis2 , 1}, 
{ Dis2 , 1}, 
{ Dis2 , 2 }, 
{ Dis2 , 4}, 
{ D2 , 2 }, 
{ Cis2 , 2 }, 
{ C2 , 2 }, 
{ C3 , 2 }, 
{ H2 , 6}, 
{ G2 , 2 }, 
{ F2 , 2 }, 
{ G2 , 6} 
};

#define WARS_LAENGE 126
flash char WarsSong[WARS_LAENGE][2] = {
{ Silence , 1 },
{ D2  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ D2  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ D2  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ Ais1  , 2 }, 
{ Silence , 1 }, 
{ F2  , 1 }, 
{ D2  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ Ais1  , 2 }, 
{ Silence , 1 }, 
{ F2  , 1 }, 
{ D2  , 4 }, 
{ Silence , 2 }, 
{ Silence , 2 }, 
{ A2  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ A2  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ A2  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ Ais2  , 2 }, 
{ Silence , 1 }, 
{ F2  , 1 }, 
{ Cis2  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ Ais1  , 2 }, 
{ Silence , 1 }, 
{ F2  , 1 }, 
{ D2  , 4 }, 
{ Silence , 2 }, 
{ Silence , 2 }, 
{ D3  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ D2  , 2 }, 
{ Silence , 1 }, 
{ D2  , 1 }, 
{ D3  , 2 }, 
{ Silence , 2 }, 
{ Cis3  , 2 }, 
{ Silence , 1 }, 
{ C3  , 1 }, 
{ H2  , 1 }, 
{ Ais2  , 1 }, 
{ H2  , 2 }, 
{ Silence , 2 }, 
{ Dis2  , 1 }, 
{ Silence , 1 }, 
{ Gis2  , 2 }, 
{ Silence , 2 }, 
{ G2  , 2 }, 
{ Silence , 1 }, 
{ Fis2  , 1 }, 
{ F2  , 1 }, 
{ E2  , 1 }, 
{ F2  , 2 }, 
{ Silence , 2 }, 
{ Ais1  , 1 }, 
{ Silence , 1 }, 
{ Cis2  , 2 }, 
{ Silence , 2 }, 
{ Ais1  , 2 }, 
{ Silence , 1 }, 
{ Cis2  , 1 }, 
{ F2  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ D2  , 2 }, 
{ Silence , 1 }, 
{ F2  , 1 }, 
{ A2  , 4 }, 
{ Silence , 2 }, 
{ Silence , 2 }, 
{ D3  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ D2  , 2 }, 
{ Silence , 1 }, 
{ D2  , 1 }, 
{ D3  , 2 }, 
{ Silence , 2 }, 
{ Cis3  , 2 }, 
{ Silence , 1 }, 
{ C3  , 1 }, 
{ H2  , 1 }, 
{ Ais2  , 1 }, 
{ H2  , 2 }, 
{ Silence , 2 }, 
{ Dis2  , 1 }, 
{ Silence , 1 }, 
{ Gis2  , 2 }, 
{ Silence , 2 }, 
{ G2  , 2 }, 
{ Silence , 1 }, 
{ Fis2  , 1 }, 
{ F2  , 1 }, 
{ E2  , 1 }, 
{ F2  , 2 }, 
{ Silence , 2 }, 
{ Ais1  , 1 }, 
{ Silence , 1 }, 
{ Cis2  , 2 }, 
{ Silence , 2 }, 
{ Ais1  , 2 }, 
{ Silence , 1 }, 
{ F2  , 1 }, 
{ D2  , 2 }, 
{ Silence , 1 }, 
{ Silence , 1 }, 
{ Ais1  , 2 }, 
{ Silence , 1 }, 
{ F2  , 1 }, 
{ D2  , 4 }, 
{ Silence , 2 }
};

#define BABY_LAENGE 23
flash char BabySong[BABY_LAENGE][2] = {
{ Silence , 1 },
{   C2 , 2 }, 
{   E2 , 2 }, 
{   C2 , 2 }, 
{   G2 , 2 }, 
{   C2 , 2 }, 
{   C3 , 2 }, 
{   H2 , 1 }, 
{   A2 , 1 }, 
{   G2 , 1 }, 
{   A2 , 1 }, 
{   G2 , 1 }, 
{   F2 , 1 }, 
{   E2 , 1 }, 
{   F2 , 1 }, 
{   E2 , 1 }, 
{   D2 , 1 }, 
{   C2 , 2 }, 
{   E2 , 2 }, 
{   G2 , 2 }, 
{   E2 , 2 }, 
{   C3 , 2 }, 
{   G2 , 2 } 
};
#define VOY_LAENGE 46
flash char VoySong[VOY_LAENGE][2] = {
   { Silence , 1 },
   {  Cis2, 4 },
   {  Fis1, 4}, 
   {  Fis2, 4 },
   {  F2, 2 },
   {  Cis2, 1 },
   {  Cis2, 2 },
   {  Dis2, 1 },
   {  Dis2, 2 },
   {  Cis2, 1 },
   {  Cis2, 4 },
   {  H1,2 },
   {  Silence, 1 },
   {  Fis1, 1 },
   {  Cis2, 1 },
   {  Fis1, 4 },
   {  Ais1, 1 },
   {  Cis2, 1 },
   {  Gis1, 4 },
   {  Silence,2 },
   {  H1, 1 },
   {  Dis1, 4 },
   {  Gis1, 2 },
   {  F1, 8 },
   {  Silence, 1 },
   {  Cis2, 4 },
   {  Fis1, 4 },
   {  Fis2, 4 },
   {  F2, 2 },
   {  Cis2, 1 },
   {  Cis2, 2 },
   {  Dis2, 1 },
   {  Dis2, 2 },
   {  Cis2, 1}, 
   {  Ais2, 4 },
   {  Fis2, 2 },
   {  Silence, 1 },
   {  Dis2, 1 },
   {  Cis2, 1 },
   {  Fis1, 4 },
   {  Silence, 1 },
   {  Cis2, 1 },
   {  Gis1, 1 },
   {  Cis1, 4 },
   {  Gis1, 2 },
   {  Fis1, 16 }
 };
// --------------------------------------------------

#define M_C     17//262  /* Middle C */
#define M_C_S   31//278
#define M_D     43//294
#define M_D_S   56//312
#define M_E     67//330
#define M_F     77//350
#define M_F_S   87//370
#define M_G     97//392
#define M_G_S  106//416
#define C_A    114//440
#define C_A_S  122//467
#define C_B_F  122//467
#define C_B    130//495
#define C_C    137//523
#define C_C_S  143//554
#define C_D    150//588
#define C_D_S  156//623
#define C_E    161//660
#define C_F    167//699
#define C_F_S  171//741
#define C_G    176//785


#define D_Cr   6     /* Dotted crochet */
#define Mi     8     /* Minim          */
#define Cr     4     /* Crochet        */
#define Qu     2     /* Quaver         */
#define S_Q    1     /* Semi quaver    */
#define SE     16    /* Semibreve      */

#define HAYDN_LAENGE 74
flash char HaydnSong[HAYDN_LAENGE][2] = {  
                                    { Silence , 1 },
                                    { M_F,D_Cr} ,
                                    { M_G,Qu} ,
                                    { C_A,Cr} ,
                                    { M_G,Cr} ,  // Bar 1
                                    { C_B_F,Cr} ,
                                    { C_A,Cr} ,
                                    { M_G,Qu} ,
                                    { M_E,Qu} ,
                                    { M_F,Cr} , // Bar 2
                                    { C_D,Cr} ,
                                    { C_C,Cr} ,
                                    { C_B_F,Cr} ,
                                    { C_A,Cr} ,  // Bar 3
                                    { M_G,Cr} , 
                                    { C_A,Qu} ,
                                    { M_F,Qu} ,
                                    { C_C,Mi} , // Bar 4
                                    { M_F,D_Cr } , // Bar 5
                                    { M_G,Qu } , 
                                    { C_A,Cr } ,
                                    { M_G,Cr } , 
                                    { C_B_F,Cr } , // Bar 6
                                    { C_A,Cr } ,             
                                    { M_G,Qu } ,           
                                    { M_E,Qu } ,
                                    { M_F,Cr } ,
                                    { C_D,Cr } ,  // Bar 7
                                    { C_C,Cr } ,
                                    { C_B_F,Cr } ,
                                    { C_A,Cr } ,
                                    { M_G,Cr } , // Bar 8
                                    { C_A,Qu } ,
                                    { M_F,Qu } ,
                                    { C_C,Mi } ,
                                    { M_G,Cr } ,  // Bar 9
                                    { C_A,Cr } ,                                    
                                    { M_G,Qu } ,
                                    { M_E,Qu } ,
                                    { M_C,Cr } ,
                                    { C_B_F,Cr } ,  // Bar 10
                                    { C_A,Cr } ,
                                    { M_G,Qu } ,
                                    { M_E,Qu } ,
                                    { M_C,Cr } ,
                                    { C_C,Cr } ,  // Bar 11
                                    { C_B_F,Cr } ,           
                                    { C_A,D_Cr } ,
                                    { C_A,Qu } ,
                                    { C_B,D_Cr } ,  // Bar 12                                  
                                    { C_B_F,Qu } ,
                                    { C_C,Mi } ,
                                    { C_F,D_Cr } ,  // Bar 13
                                    { C_E,Qu } ,
                                    { C_D,Cr },
                                    { C_C,Cr } ,
                                    { C_D,D_Cr } , // Bar 14
                                    { C_C,Qu } ,  
                                    { C_C,Qu } ,
                                    { C_B_F,Qu } ,
                                    { C_A,Cr } ,
                                    { M_G,Cr } ,  // Bar 15
                                    { C_A,Qu } ,
                                    { C_B_F,Qu } ,
                                    { C_C,Qu } ,
                                    { C_D,Qu } ,
                                    { C_B_F,Qu } ,
                                    { M_G,Qu } ,
                                    { M_F,Cr } ,  // Bar 16
                                    { C_A,Qu } ,
                                    { M_G,Qu } ,
                                    { M_F,Mi } ,
                                    { Silence,SE },
                                    { Silence,SE }
            } ;  

#pragma once

#define CheckNull2(p) { if(p==NULL) return; }
#define CheckNullResult2(p, result) { if(p==NULL) return result; }

#define CheckTrue2(p) { if(p == true) return;}
#define CheckTrueResult2(p, result) { if(p==true) return result; }

#define CheckFalse2(p) { if(p == false) return;}
#define CheckFalseResult2(p, result) { if(p==false) return result; }
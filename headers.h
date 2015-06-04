enum {
  ERR_MISSING_H_OR_V = 49,
  ERR_UNABLE_TO_CHANGE_RESOLUTION = 50,
};


typedef struct Resolution {
  int width;
  int height;
} Resolution;


/* following functions must be implemented for OS */
Resolution fetchRes();
int changeRes(int h, int v);


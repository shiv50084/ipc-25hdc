/* LibTomCrypt, modular cryptographic library -- Tom St Denis
 *
 * LibTomCrypt is a library that provides various cryptographic
 * algorithms in a highly modular and flexible manner.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@gmail.com, http://libtomcrypt.com
 */
#include "tomcrypt.h"

/**
   @file lrw_done.c
   LRW_MODE implementation, Free resources, Tom St Denis
*/

#ifdef LTC_LRW_MODE

/**
  Terminate a LRW state
  @param lrw   The state to terminate
  @return CRYPT_OK if successful
*/
int lrw_done(symmetric_LRW *lrw) 
{
   int err;

   LTC_ARGCHK(lrw != NULL);
 
   if ((err = cipher_is_valid(lrw->cipher)) != CRYPT_OK) {
      return err;
   }
   cipher_descriptor[lrw->cipher].done(&lrw->key);

   return CRYPT_OK;
}

#endif
/* $Source: /home/cvsroot/RT288x_SDK/source/user/dropbear-0.52/libtomcrypt/src/modes/lrw/lrw_done.c,v $ */
/* $Revision: 1.1 $ */
/* $Date: 2010-07-02 06:29:18 $ */

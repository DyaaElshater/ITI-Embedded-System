/*********************************************/
/**Author 	  : Dyaa Elshater				 */
/**Date		  : 7/11/2019					 */
/**Descrption : Standard types				 */
/**Version 	  : 3.0 v
/*********************************************/
#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_
typedef unsigned char 		 u8	;
typedef signed char 		 s8	;
typedef unsigned short int  u16	;
typedef signed short int    s16	;
typedef unsigned long int   u32	;
typedef signed long int     s32	;
typedef float 				f32	;
typedef double				f64	;
typedef long double		   f128	;
/** Pointer to function 	 				 */
typedef void	(*vidpfvid   )(void	 )	;
typedef void	(*vidpfint   )(int   ) 	;
typedef void	(*vidpfflt   )(float )	;
typedef void	(*vidpfdb    )(double)	;
typedef void	(*vidpfchar  )(char  )	;
typedef int 	(*intpfvid   )(void  )	;
typedef int 	(*intpfint   )(int   ) 	;
typedef int		(*intpfflt   )(float )	;
typedef int		(*intpfdb    )(double)	;
typedef int		(*intpfchar  )(char  )	;
typedef float	(*fltpfvid   )(void  )	;
typedef float	(*fltpfint   )(int   ) 	;
typedef float	(*fltpfflt   )(float )	;
typedef float	(*fltpfdb    )(double)	;
typedef float	(*fltpfchar  )(char  )	;
typedef double	(*dbpfvid    )(void  )	;
typedef double	(*dbpfint    )(int   ) 	;
typedef double	(*dbpfflt    )(float )	;
typedef double	(*dbpfdb     )(double)	;
typedef double	(*dbpfchar   )(char  )	;
typedef char	(*charpfvid	 )(void  )	;
typedef char	(*dbcharpfint)(int   ) 	;
typedef char	(*dbcharpfflt)(float )	;
typedef char	(*dbcharpfdb )(double)	;
typedef char	(*charpfchar )(char  )	;
/** Pointer to function using u8 types					 */
typedef u8		(*u8pfvid 	)(void)	;
typedef u8		(*u8pfu8  	)(u8  )	;
typedef u8		(*u8pfs8  	)(s8  )	;
typedef u8		(*u8pfu16 	)(u16 )	;
typedef u8		(*u8pfs16 	)(s16 )	;
typedef u8		(*u8pfu32 	)(u32 )	;
typedef u8		(*u8pfs32 	)(s32 )	;
typedef u8		(*u8pff32 	)(f32 )	;
typedef u8		(*u8pff64 	)(f64 )	;
typedef u8		(*u8pff128	)(f128)	;
typedef s8		(*s8pfvid 	)(void)	;
typedef s8		(*s8pfu8  	)(u8  )	;
typedef s8		(*s8pfs8  	)(s8  )	;
typedef s8		(*s8pfu16 	)(u16 )	;
typedef s8		(*s8pfs16 	)(s16 )	;
typedef s8		(*s8pfu32 	)(u32 )	;
typedef s8		(*s8pfs32 	)(s32 )	;
typedef s8		(*s8pff32 	)(f32 )	;
typedef s8		(*s8pff64 	)(f64 )	;
typedef s8		(*s8pff128	)(f128)	;
typedef u16		(*u16pfvid  )(void)	;
typedef u16		(*u16pfu8   )(u8  )	;
typedef u16		(*u16pfs8   )(s8  )	;
typedef u16		(*u16pfu16  )(u16 )	;
typedef u16		(*u16pfs16  )(s16 )	;
typedef u16		(*u16pfu32  )(u32 )	;
typedef u16		(*u16pfs32  )(s32 )	;
typedef u16		(*u16pff32  )(f32 )	;
typedef u16		(*u16pff64  )(f64 )	;
typedef u16		(*u16pff128 )(f128)	;
typedef s16		(*s16pfvid  )(void)	;
typedef s16		(*s16pfu8   )(u8  )	;
typedef s16		(*s16pfs8   )(s8  )	;
typedef s16		(*s16pfu16  )(u16 )	;
typedef s16		(*s16pfs16  )(s16 )	;
typedef s16		(*s16pfu32  )(u32 )	;
typedef s16		(*s16pfs32  )(s32 )	;
typedef s16		(*s16pff32  )(f32 )	;
typedef s16		(*s16pff64  )(f64 )	;
typedef s16		(*s16pff128 )(f128)	;
typedef u32		(*u32pfvid  )(void)	;
typedef u32		(*u32pfu8   )(u8  )	;
typedef u32		(*u32pfs8   )(s8  )	;
typedef u32		(*u32pfu16  )(u16 )	;
typedef u32		(*u32pfs16  )(s16 )	;
typedef u32		(*u32pfu32  )(u32 )	;
typedef u32		(*u32pfs32  )(s32 )	;
typedef u32		(*u32pff32  )(f32 )	;
typedef u32		(*u32pff64  )(f64 )	;
typedef u32		(*u32pff128 )(f128)	;
typedef s32		(*s32pfvid  )(void)	;
typedef s32		(*s32pfu8   )(u8  )	;
typedef s32		(*s32pfs8   )(s8  )	;
typedef s32		(*s32pfu16  )(u16 )	;
typedef s32		(*s32pfs16  )(s16 )	;
typedef s32		(*s32pfu32  )(u32 )	;
typedef s32		(*s32pfs32  )(s32 )	;
typedef s32		(*s32pff32  )(f32 )	;
typedef s32		(*s32pff64  )(f64 )	;
typedef s32		(*s32pff128 )(f128)	;
typedef f32		(*f32pfvid  )(void)	;
typedef f32		(*f32pfu8   )(u8  )	;
typedef f32		(*f32pfs8   )(s8  )	;
typedef f32		(*f32pfu16  )(u16 )	;
typedef f32		(*f32pfs16  )(s16 )	;
typedef f32		(*f32pfu32  )(u32 )	;
typedef f32		(*f32pfs32  )(s32 )	;
typedef f32		(*f32pff32  )(f32 )	;
typedef f32		(*f32pff64  )(f64 )	;
typedef f32		(*f32pff128 )(f128)	;
typedef f64		(*f64pfvid  )(void)	;
typedef f64		(*f64pfu8   )(u8  )	;
typedef f64		(*f64pfs8   )(s8  )	;
typedef f64		(*f64pfu16  )(u16 )	;
typedef f64		(*f64pfs16  )(s16 )	;
typedef f64		(*f64pfu32  )(u32 )	;
typedef f64		(*f64pfs32  )(s32 )	;
typedef f64		(*f64pff32  )(f32 )	;
typedef f64		(*f64pff64  )(f64 )	;
typedef f64		(*f64pff128 )(f128)	;
typedef f128	(*f128pfvid )(void)	;
typedef f128	(*f128pfu8  )(u8  )	;
typedef f128	(*f128pfs8  )(s8  )	;
typedef f128	(*f128pfu16 )(u16 )	;
typedef f128	(*f128pfs16 )(s16 )	;
typedef f128	(*f128pfu32 )(u32 )	;
typedef f128	(*f128pfs32 )(s32 )	;
typedef f128	(*f128pff32 )(f32 )	;
typedef f128	(*f128pff64 )(f64 )	;
typedef f128	(*f128pff128)(f128)	;

/** Descrption	:	Error Status			*/
typedef	enum error
{
	OK	=	0,
	NOK	=	4,
	INDEX_OUT_OF_RANGE = 8 ,
	NULL_POINTRE	=	16
}Error_Status	;

#endif
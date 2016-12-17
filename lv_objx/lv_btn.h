/**
 * @file lv_btn.h
 * 
 */

#ifndef LV_BTN_H
#define LV_BTN_H

/*********************
 *      INCLUDES
 *********************/
#include "lv_conf.h"
#if USE_LV_BTN != 0

#include "lv_rect.h"
#include "../lv_obj/lv_dispi.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef enum
{
    LV_BTN_STATE_PR,
    LV_BTN_STATE_REL,
    LV_BTN_STATE_TGL_PR,
    LV_BTN_STATE_TGL_REL,
    LV_BTN_STATE_INA,
    LV_BTN_STATE_NUM,
}lv_btn_state_t;

typedef enum
{
	LV_ACTION_RES_OK = 0,
	LV_ACTION_RES_INV = 0,
}lv_action_res_t;

typedef lv_action_res_t (*lv_btn_action_t) (lv_obj_t*, lv_dispi_t *);

typedef struct
{
	uint8_t light_en :1;
	uint8_t transp :1;
	uint8_t empty :1;
}lv_btns_bits_t;

/*Style of button*/
typedef struct
{
	lv_rects_t rects;	/*Style of ancestor*/
	/*New style element for this type */
	color_t mcolor[LV_BTN_STATE_NUM];
	color_t gcolor[LV_BTN_STATE_NUM];
	color_t bcolor[LV_BTN_STATE_NUM];
	color_t lcolor[LV_BTN_STATE_NUM];
	lv_btns_bits_t flags[LV_BTN_STATE_NUM];
}lv_btns_t;

/*Built-in styles of button*/
typedef enum
{
	LV_BTNS_DEF,
	LV_BTNS_TRANSP,
	LV_BTNS_BORDER,
}lv_btns_builtin_t;

/*Data of button*/
typedef struct
{       
	lv_rect_ext_t rect_ext; /*Ext. of ancestor*/
	/*New data for this type */
	lv_btn_action_t pr_action;
	lv_btn_action_t rel_action;
	lv_btn_action_t lpr_action;
	lv_btn_action_t lpr_rep_action;
    
    lv_btn_state_t state;
    uint8_t tgl :1;      /*1: Toggle enabled*/
    uint8_t lpr_exec :1; /*1: long press action executed (Not for user)*/
}lv_btn_ext_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
/*Create function*/
lv_obj_t * lv_btn_create(lv_obj_t * par, lv_obj_t * copy);

bool lv_btn_signal(lv_obj_t * btn, lv_signal_t sign, void * param);
lv_btns_t * lv_btns_get(lv_btns_builtin_t style, lv_btns_t * copy);

void lv_btn_set_tgl(lv_obj_t * btn, bool tgl);
void lv_btn_set_state(lv_obj_t * btn, lv_btn_state_t state);
void lv_btn_set_pr_action(lv_obj_t * btn, lv_btn_action_t pr_action);
void lv_btn_set_rel_action(lv_obj_t * btn, lv_btn_action_t rel_action);
void lv_btn_set_lpr_action(lv_obj_t * btn, lv_btn_action_t lpr_action);
void lv_btn_set_lpr_rep_action(lv_obj_t * btn, lv_btn_action_t lpr_rep_action);

bool lv_btn_get_tgl(lv_obj_t * btn);
lv_btn_state_t lv_btn_get_state(lv_obj_t * btn);

/**********************
 *      MACROS
 **********************/

#endif

#endif

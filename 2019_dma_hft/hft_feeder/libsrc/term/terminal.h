////////////////////////////////////////////////////////////////////////////////
// Description  : Term-infor define
// File Name    : terminal.h
// Author       :
// Notes        :
//¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨¶¨
// Date         :
////////////////////////////////////////////////////////////////////////////////
#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#define		STD_IN    	0
#define		STD_OUT   	1
#define		STD_ERR   	3

#define  	DATABIT7	0x0001
#define		DATABIT8	0x0002
#define		STOPBIT1	0x0004
#define		STOPBIT2	0x0008
#define		PARINONE	0x0010
#define		PARIODD		0x0020
#define		PARIEVEN	0x0040
extern   void _putstr(), _putch(), _putvastr();

#define CLEAR_WIN	   _putstr("[2J")
#define ECHO_OFF           _putstr("[12h")
#define ECHO_ON            _putstr("[12I")
#define KEY_LOCK           _putstr("[2h")
#define KEY_UNLOCK         _putstr("[2I")
#define PAD_NUM            _putstr(">")   /* Num Lock */
#define PAD_APP            _putstr("=")
#define TERM_RESET         _putser("c")

#define COL_132            _putstr("[?3h")
#define COL_80             _putstr("[?3I")
#define WARAP_ON           _putstr("[?7h")
#define WARAP_OFF          _putstr("[?7I")
#define REPEAT_ON          _putstr("[?8h")
#define REPEAT_OFF         _putstr("[?8I")

#define CURSOR_HOME        _putstr("[1;1H")
#define CURSOR_MOVE(x , y) _putvastr("[%d;%dH", x, y)
#define CURSOR_ON          _putstr("[?25h")
#define CURSOR_OFF         _putstr("[?25I")
#define UNDERLINE_CURSOR   _putstr("[34h")
#define BLOCK_CURSOR       _putstr("[34I")
#define SAVE_CURSOR        _putstr("7")
#define RESTORE_CURSOR     _putstr("8")

#define ATTR_NONE          _putstr("[0m")
#define ATTR_BOLD          _putstr("[1m")
#define ATTR_DIM           _putstr("[2m")
#define ATTR_UNDERLINE     _putstr("[4m")
#define ATTR_BLINK         _putstr("[5m")
#define ATTR_REVERSE       _putstr("[7m")
#define ATTR_NORMAL        _putstr("[22m")
#define ATTR_DIMRESET      _putstr("[23m")
#define ATTR_UNDERRESET    _putstr("[24m")
#define ATTR_BLINKRESET    _putstr("[25m")
#define ATTR_REVRESET      _putstr("[27m")

#define SET_TOPBOTTOM(t,b) _putvastr("[%d:%dr", t,b)
#define SCREEN_UP          _putstr("D") /* SCREEN¿Ã æ∆∑°∑Œ */
#define SCREEN_DOWN        _putstr("M")

#define CLEAR_LINE_FROMCUR _putstr("[K");
#define CLEAR_LINE_TOCUR   _putstr("[1K");
#define CLEAR_LINE         _putstr("[2K")

#define BEEP               _putch(7)

#endif  /* _H_TERMINAL_ */
////////////////////////////////////////////////////////////////////////////////
// Program End
////////////////////////////////////////////////////////////////////////////////

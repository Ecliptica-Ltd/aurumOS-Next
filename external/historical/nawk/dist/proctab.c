#include <stdio.h>
#include "awk.h"
#include "awkgram.h"

static const char * const printname[96] = {
	"FIRSTTOKEN",	/* 257 */
	"PROGRAM",	/* 258 */
	"PASTAT",	/* 259 */
	"PASTAT2",	/* 260 */
	"XBEGIN",	/* 261 */
	"XEND",	/* 262 */
	"NL",	/* 263 */
	"ARRAY",	/* 264 */
	"MATCH",	/* 265 */
	"NOTMATCH",	/* 266 */
	"MATCHOP",	/* 267 */
	"FINAL",	/* 268 */
	"DOT",	/* 269 */
	"ALL",	/* 270 */
	"CCL",	/* 271 */
	"NCCL",	/* 272 */
	"CHAR",	/* 273 */
	"OR",	/* 274 */
	"STAR",	/* 275 */
	"QUEST",	/* 276 */
	"PLUS",	/* 277 */
	"EMPTYRE",	/* 278 */
	"ZERO",	/* 279 */
	"AND",	/* 280 */
	"BOR",	/* 281 */
	"APPEND",	/* 282 */
	"EQ",	/* 283 */
	"GE",	/* 284 */
	"GT",	/* 285 */
	"LE",	/* 286 */
	"LT",	/* 287 */
	"NE",	/* 288 */
	"IN",	/* 289 */
	"ARG",	/* 290 */
	"BLTIN",	/* 291 */
	"BREAK",	/* 292 */
	"CLOSE",	/* 293 */
	"CONTINUE",	/* 294 */
	"DELETE",	/* 295 */
	"DO",	/* 296 */
	"EXIT",	/* 297 */
	"FOR",	/* 298 */
	"FUNC",	/* 299 */
	"GENSUB",	/* 300 */
	"SUB",	/* 301 */
	"GSUB",	/* 302 */
	"IF",	/* 303 */
	"INDEX",	/* 304 */
	"LSUBSTR",	/* 305 */
	"MATCHFCN",	/* 306 */
	"NEXT",	/* 307 */
	"NEXTFILE",	/* 308 */
	"ADD",	/* 309 */
	"MINUS",	/* 310 */
	"MULT",	/* 311 */
	"DIVIDE",	/* 312 */
	"MOD",	/* 313 */
	"ASSIGN",	/* 314 */
	"ASGNOP",	/* 315 */
	"ADDEQ",	/* 316 */
	"SUBEQ",	/* 317 */
	"MULTEQ",	/* 318 */
	"DIVEQ",	/* 319 */
	"MODEQ",	/* 320 */
	"POWEQ",	/* 321 */
	"PRINT",	/* 322 */
	"PRINTF",	/* 323 */
	"SPRINTF",	/* 324 */
	"ELSE",	/* 325 */
	"INTEST",	/* 326 */
	"CONDEXPR",	/* 327 */
	"POSTINCR",	/* 328 */
	"PREINCR",	/* 329 */
	"POSTDECR",	/* 330 */
	"PREDECR",	/* 331 */
	"VAR",	/* 332 */
	"IVAR",	/* 333 */
	"VARNF",	/* 334 */
	"CALL",	/* 335 */
	"NUMBER",	/* 336 */
	"STRING",	/* 337 */
	"REGEXPR",	/* 338 */
	"GETLINE",	/* 339 */
	"RETURN",	/* 340 */
	"SPLIT",	/* 341 */
	"SUBSTR",	/* 342 */
	"WHILE",	/* 343 */
	"CAT",	/* 344 */
	"NOT",	/* 345 */
	"UMINUS",	/* 346 */
	"UPLUS",	/* 347 */
	"POWER",	/* 348 */
	"DECR",	/* 349 */
	"INCR",	/* 350 */
	"INDIRECT",	/* 351 */
	"LASTTOKEN",	/* 352 */
};


Cell *(*proctab[96])(Node **, int) = {
	nullproc,	/* FIRSTTOKEN */
	program,	/* PROGRAM */
	pastat,	/* PASTAT */
	dopa2,	/* PASTAT2 */
	nullproc,	/* XBEGIN */
	nullproc,	/* XEND */
	nullproc,	/* NL */
	array,	/* ARRAY */
	matchop,	/* MATCH */
	matchop,	/* NOTMATCH */
	nullproc,	/* MATCHOP */
	nullproc,	/* FINAL */
	nullproc,	/* DOT */
	nullproc,	/* ALL */
	nullproc,	/* CCL */
	nullproc,	/* NCCL */
	nullproc,	/* CHAR */
	nullproc,	/* OR */
	nullproc,	/* STAR */
	nullproc,	/* QUEST */
	nullproc,	/* PLUS */
	nullproc,	/* EMPTYRE */
	nullproc,	/* ZERO */
	boolop,	/* AND */
	boolop,	/* BOR */
	nullproc,	/* APPEND */
	relop,	/* EQ */
	relop,	/* GE */
	relop,	/* GT */
	relop,	/* LE */
	relop,	/* LT */
	relop,	/* NE */
	instat,	/* IN */
	arg,	/* ARG */
	bltin,	/* BLTIN */
	jump,	/* BREAK */
	closefile,	/* CLOSE */
	jump,	/* CONTINUE */
	awkdelete,	/* DELETE */
	dostat,	/* DO */
	jump,	/* EXIT */
	forstat,	/* FOR */
	nullproc,	/* FUNC */
	gensub,	/* GENSUB */
	dosub,	/* SUB */
	dosub,	/* GSUB */
	ifstat,	/* IF */
	sindex,	/* INDEX */
	nullproc,	/* LSUBSTR */
	matchop,	/* MATCHFCN */
	jump,	/* NEXT */
	jump,	/* NEXTFILE */
	arith,	/* ADD */
	arith,	/* MINUS */
	arith,	/* MULT */
	arith,	/* DIVIDE */
	arith,	/* MOD */
	assign,	/* ASSIGN */
	nullproc,	/* ASGNOP */
	assign,	/* ADDEQ */
	assign,	/* SUBEQ */
	assign,	/* MULTEQ */
	assign,	/* DIVEQ */
	assign,	/* MODEQ */
	assign,	/* POWEQ */
	printstat,	/* PRINT */
	awkprintf,	/* PRINTF */
	awksprintf,	/* SPRINTF */
	nullproc,	/* ELSE */
	intest,	/* INTEST */
	condexpr,	/* CONDEXPR */
	incrdecr,	/* POSTINCR */
	incrdecr,	/* PREINCR */
	incrdecr,	/* POSTDECR */
	incrdecr,	/* PREDECR */
	nullproc,	/* VAR */
	nullproc,	/* IVAR */
	getnf,	/* VARNF */
	call,	/* CALL */
	nullproc,	/* NUMBER */
	nullproc,	/* STRING */
	nullproc,	/* REGEXPR */
	awkgetline,	/* GETLINE */
	jump,	/* RETURN */
	split,	/* SPLIT */
	substr,	/* SUBSTR */
	whilestat,	/* WHILE */
	cat,	/* CAT */
	boolop,	/* NOT */
	arith,	/* UMINUS */
	arith,	/* UPLUS */
	arith,	/* POWER */
	nullproc,	/* DECR */
	nullproc,	/* INCR */
	indirect,	/* INDIRECT */
	nullproc,	/* LASTTOKEN */
};

const char *tokname(int n)
{
	static char buf[100];

	if (n < FIRSTTOKEN || n > LASTTOKEN) {
		snprintf(buf, sizeof(buf), "token %d", n);
		return buf;
	}
	return printname[n-FIRSTTOKEN];
}

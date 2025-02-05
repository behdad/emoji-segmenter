
#line 1 "emoji_presentation_scanner_vs.rl"
/* Copyright 2024 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#line 17 "emoji_presentation_scanner_vs.c"
static const char _emoji_presentation_actions[] = {
	0, 1, 0, 1, 1, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11, 1, 12, 1, 13, 2, 2, 3, 
	2, 2, 4, 2, 2, 5
};

static const char _emoji_presentation_key_offsets[] = {
	0, 5, 7, 14, 18, 20, 21, 24, 
	29, 30, 34, 36
};

static const unsigned char _emoji_presentation_trans_keys[] = {
	3u, 7u, 13u, 0u, 2u, 14u, 15u, 2u, 
	3u, 6u, 7u, 13u, 0u, 1u, 9u, 10u, 
	11u, 12u, 10u, 12u, 10u, 4u, 10u, 12u, 
	4u, 9u, 10u, 11u, 12u, 6u, 9u, 10u, 
	11u, 12u, 8u, 10u, 9u, 10u, 11u, 12u, 
	14u, 0
};

static const char _emoji_presentation_single_lengths[] = {
	3, 2, 5, 4, 2, 1, 3, 5, 
	1, 4, 2, 5
};

static const char _emoji_presentation_range_lengths[] = {
	1, 0, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const char _emoji_presentation_index_offsets[] = {
	0, 5, 8, 15, 20, 23, 25, 29, 
	35, 37, 42, 45
};

static const char _emoji_presentation_indicies[] = {
	2, 1, 1, 1, 0, 4, 5, 3, 
	7, 8, 10, 11, 12, 6, 9, 5, 
	13, 14, 15, 0, 13, 17, 16, 13, 
	0, 17, 13, 17, 16, 17, 5, 13, 
	14, 15, 16, 5, 18, 5, 13, 14, 
	19, 18, 5, 13, 20, 5, 13, 14, 
	15, 4, 16, 0
};

static const char _emoji_presentation_trans_targs[] = {
	2, 4, 6, 2, 1, 2, 3, 3, 
	7, 2, 8, 9, 11, 0, 2, 5, 
	2, 5, 2, 10, 2
};

static const char _emoji_presentation_trans_actions[] = {
	19, 24, 24, 17, 0, 7, 27, 24, 
	24, 9, 0, 27, 24, 0, 5, 21, 
	13, 24, 15, 21, 11
};

static const char _emoji_presentation_to_state_actions[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const char _emoji_presentation_from_state_actions[] = {
	0, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const char _emoji_presentation_eof_trans[] = {
	1, 4, 0, 1, 17, 1, 17, 17, 
	19, 19, 21, 17
};

static const int emoji_presentation_start = 2;


#line 20 "emoji_presentation_scanner_vs.rl"



#line 90 "emoji_presentation_scanner_vs.rl"


static emoji_text_iter_t
scan_emoji_presentation_vs (emoji_text_iter_t p,
    const emoji_text_iter_t pe,
    bool* is_emoji,
    bool* has_vs)
{
  emoji_text_iter_t ts, te;
  const emoji_text_iter_t eof = pe;

  unsigned act;
  int cs;

  
#line 108 "emoji_presentation_scanner_vs.c"
	{
	cs = emoji_presentation_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 114 "emoji_presentation_scanner_vs.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const unsigned char *_keys;

	if ( p == pe )
		goto _test_eof;
_resume:
	_acts = _emoji_presentation_actions + _emoji_presentation_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 1:
#line 1 "NONE"
	{ts = p;}
	break;
#line 131 "emoji_presentation_scanner_vs.c"
		}
	}

	_keys = _emoji_presentation_trans_keys + _emoji_presentation_key_offsets[cs];
	_trans = _emoji_presentation_index_offsets[cs];

	_klen = _emoji_presentation_single_lengths[cs];
	if ( _klen > 0 ) {
		const unsigned char *_lower = _keys;
		const unsigned char *_mid;
		const unsigned char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _emoji_presentation_range_lengths[cs];
	if ( _klen > 0 ) {
		const unsigned char *_lower = _keys;
		const unsigned char *_mid;
		const unsigned char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _emoji_presentation_indicies[_trans];
_eof_trans:
	cs = _emoji_presentation_trans_targs[_trans];

	if ( _emoji_presentation_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _emoji_presentation_actions + _emoji_presentation_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 2:
#line 1 "NONE"
	{te = p+1;}
	break;
	case 3:
#line 85 "emoji_presentation_scanner_vs.rl"
	{act = 2;}
	break;
	case 4:
#line 86 "emoji_presentation_scanner_vs.rl"
	{act = 3;}
	break;
	case 5:
#line 87 "emoji_presentation_scanner_vs.rl"
	{act = 4;}
	break;
	case 6:
#line 84 "emoji_presentation_scanner_vs.rl"
	{te = p+1;{ *is_emoji = false; *has_vs = true; return te; }}
	break;
	case 7:
#line 86 "emoji_presentation_scanner_vs.rl"
	{te = p+1;{ *is_emoji = true; *has_vs = false; return te; }}
	break;
	case 8:
#line 87 "emoji_presentation_scanner_vs.rl"
	{te = p+1;{ *is_emoji = false; *has_vs = false; return te; }}
	break;
	case 9:
#line 85 "emoji_presentation_scanner_vs.rl"
	{te = p;p--;{ *is_emoji = true; *has_vs = true; return te; }}
	break;
	case 10:
#line 86 "emoji_presentation_scanner_vs.rl"
	{te = p;p--;{ *is_emoji = true; *has_vs = false; return te; }}
	break;
	case 11:
#line 87 "emoji_presentation_scanner_vs.rl"
	{te = p;p--;{ *is_emoji = false; *has_vs = false; return te; }}
	break;
	case 12:
#line 86 "emoji_presentation_scanner_vs.rl"
	{{p = ((te))-1;}{ *is_emoji = true; *has_vs = false; return te; }}
	break;
	case 13:
#line 1 "NONE"
	{	switch( act ) {
	case 2:
	{{p = ((te))-1;} *is_emoji = true; *has_vs = true; return te; }
	break;
	case 3:
	{{p = ((te))-1;} *is_emoji = true; *has_vs = false; return te; }
	break;
	case 4:
	{{p = ((te))-1;} *is_emoji = false; *has_vs = false; return te; }
	break;
	}
	}
	break;
#line 243 "emoji_presentation_scanner_vs.c"
		}
	}

_again:
	_acts = _emoji_presentation_actions + _emoji_presentation_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 0:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 254 "emoji_presentation_scanner_vs.c"
		}
	}

	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _emoji_presentation_eof_trans[cs] > 0 ) {
		_trans = _emoji_presentation_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	}

#line 107 "emoji_presentation_scanner_vs.rl"


  /* Should not be reached. */
  *is_emoji = false;
  *has_vs = false;
  return pe;
}

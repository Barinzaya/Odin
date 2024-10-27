#pragma warning(push)
#pragma warning(disable: 4245)

extern "C" {
#include "utf8proc/utf8proc.c"
}
#pragma warning(pop)


gb_internal bool rune_is_letter(Rune r) {
	if (r < 0x80) {
		if (r == '_') {
			return true;
		}
		return ((cast(u32)r | 0x20) - 0x61) < 26;
	}
	switch (utf8proc_category(r)) {
	case UTF8PROC_CATEGORY_LU:
	case UTF8PROC_CATEGORY_LL:
	case UTF8PROC_CATEGORY_LT:
	case UTF8PROC_CATEGORY_LM:
	case UTF8PROC_CATEGORY_LO:
		return true;
	}
	return false;
}

gb_internal bool rune_is_digit(Rune r) {
	if (r < 0x80) {
		return (cast(u32)r - '0') < 10;
	}
	return utf8proc_category(r) == UTF8PROC_CATEGORY_ND;
}

gb_internal bool rune_is_letter_or_digit(Rune r) {
	if (r < 0x80) {
		if (r == '_') {
			return true;
		}
		if (((cast(u32)r | 0x20) - 0x61) < 26) {
			return true;
		}
		return (cast(u32)r - '0') < 10;
	}
	switch (utf8proc_category(r)) {
	case UTF8PROC_CATEGORY_LU:
	case UTF8PROC_CATEGORY_LL:
	case UTF8PROC_CATEGORY_LT:
	case UTF8PROC_CATEGORY_LM:
	case UTF8PROC_CATEGORY_LO:
		return true;
	case UTF8PROC_CATEGORY_ND:
		return true;
	}
	return false;
}

gb_internal bool rune_is_whitespace(Rune r) {
	switch (r) {
	case ' ':
	case '\t':
	case '\n':
	case '\r':
		return true;
	}
	return false;
}


gb_global u8 const global__utf8_first[256] = {
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x00-0x0F
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x10-0x1F
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x20-0x2F
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x30-0x3F
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x40-0x4F
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x50-0x5F
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x60-0x6F
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, // 0x70-0x7F
	0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, // 0x80-0x8F
	0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, // 0x90-0x9F
	0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, // 0xA0-0xAF
	0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, // 0xB0-0xBF
	0xf1, 0xf1, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, // 0xC0-0xCF
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, // 0xD0-0xDF
	0x13, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x23, 0x03, 0x03, // 0xE0-0xEF
	0x34, 0x04, 0x04, 0x04, 0x44, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, // 0xF0-0xFF
};

typedef struct Utf8AcceptRange {
	u8 lo, hi;
} Utf8AcceptRange;

gb_global Utf8AcceptRange const global__utf8_accept_ranges[] = {
	{0x80, 0xbf},
	{0xa0, 0xbf},
	{0x80, 0x9f},
	{0x90, 0xbf},
	{0x80, 0x8f},
};


gb_internal isize utf8_decode(u8 const *str, isize str_len, Rune *codepoint_out) {
	isize width = 0;
	Rune codepoint = GB_RUNE_INVALID;

	if (str_len > 0) {
		u8 s0 = str[0];
		u8 x = global__utf8_first[s0], sz;
		u8 b1, b2, b3;
		Utf8AcceptRange accept;
		if (x >= 0xf0) {
			Rune mask = -cast(Rune)(x & 1);
			codepoint = (cast(Rune)s0 & (~mask)) | (GB_RUNE_INVALID & mask);
			width = 1;
			goto end;
		}
		if (s0 < 0x80) {
			codepoint = s0;
			width = 1;
			goto end;
		}

		sz = x&7;
		accept = global__utf8_accept_ranges[x>>4];
		if (str_len < gb_size_of(sz))
			goto invalid_codepoint;

		b1 = str[1];
		if (b1 < accept.lo || accept.hi < b1)
			goto invalid_codepoint;

		if (sz == 2) {
			codepoint = (cast(Rune)s0&0x1f)<<6 | (cast(Rune)b1&0x3f);
			width = 2;
			goto end;
		}

		b2 = str[2];
		if (!gb_is_between(b2, 0x80, 0xbf))
			goto invalid_codepoint;

		if (sz == 3) {
			codepoint = (cast(Rune)s0&0x1f)<<12 | (cast(Rune)b1&0x3f)<<6 | (cast(Rune)b2&0x3f);
			width = 3;
			goto end;
		}

		b3 = str[3];
		if (!gb_is_between(b3, 0x80, 0xbf))
			goto invalid_codepoint;

		codepoint = (cast(Rune)s0&0x07)<<18 | (cast(Rune)b1&0x3f)<<12 | (cast(Rune)b2&0x3f)<<6 | (cast(Rune)b3&0x3f);
		width = 4;
		goto end;

	invalid_codepoint:
		codepoint = GB_RUNE_INVALID;
		width = 1;
	}

end:
	if (codepoint_out) *codepoint_out = codepoint;
	return width;
}

// NOTE(Feoramund): It's down here because I made UCG use the utf8_decode above to avoid duplicating code.
extern "C" {
#include "ucg/ucg.c"
}

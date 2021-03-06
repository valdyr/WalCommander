/*
 * Part of Wal Commander GitHub Edition
 * https://github.com/corporateshark/WalCommander
 * walcommander@linderdaum.com
 */

#pragma once

#include <vector>

struct SearchAndReplaceParams
{
	std::vector<unicode_t> mask;
	std::vector<unicode_t> txt;
	std::vector<unicode_t> to;
	bool sens;
	SearchAndReplaceParams(): sens( false ) { mask.push_back( '*' ); mask.push_back( 0 ); }
	SearchAndReplaceParams( const SearchAndReplaceParams& a )
	{
		mask = new_unicode_str( a.mask.data() );
		txt = new_unicode_str( a.txt.data() );
		to = new_unicode_str( a.to.data() );
	}
	SearchAndReplaceParams& operator = ( const SearchAndReplaceParams& a )
	{
		mask = new_unicode_str( a.mask.data() );
		txt = new_unicode_str( a.txt.data() );
		to = new_unicode_str( a.to.data() );
		return *this;
	}
};

bool DoSearchDialog( NCDialogParent* parent, SearchAndReplaceParams* params );
bool DoFileSearchDialog( NCDialogParent* parent, SearchAndReplaceParams* params );
bool DoReplaceEditDialog( NCDialogParent* parent, SearchAndReplaceParams* params );

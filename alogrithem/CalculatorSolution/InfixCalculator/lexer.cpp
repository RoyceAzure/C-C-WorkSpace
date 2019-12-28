#include "lexer.h"

namespace Lexer
{
	// to eat up any blank space
	std::istream& ClassLexer::get_next_char(char& chr)
	{
		while (this->m_stream.get(chr) && 
			(std::isblank(chr) || chr == '\n'));

		return this->m_stream;
	}

	Token& ClassLexer::get_current_token()
	{
		return this->m_current_token;
	}

	Token ClassLexer::fetch_next_token()
	{
		// lac stands for look ahead character
		char lac = 0;

		// read in a char from the stream
		this->get_next_char(lac);

		switch (lac)
		{
			case 0: // eof or end of file, stream
				this->m_current_token = { Kind::end };
				return this->m_current_token;

			case ';': case '+': case '-': case '*': case '/':
			case '=': case '(': case ')':
				this->m_current_token = { static_cast<Kind>(lac) };
				return this->m_current_token;

			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9': case '.':
			{
				// push back the look ahead char
				// back to the stream
				this->m_stream.putback(lac);

				// read in a number
				this->m_stream >> this->m_current_token.number;

				// set the token type to number
				this->m_current_token.kind = Kind::number;

				return this->m_current_token;
			}

			default:
			{
				if (std::isalpha(lac))
				{
					this->m_current_token.name = lac;

					while (this->m_stream.get(lac) &&
						std::isalnum(lac))
						this->m_current_token.name += lac;

					// IMPORTANT
					// at the point, lac is neither a alphabet
					// nor a number, so we have to pushback lac
					this->m_stream.putback(lac);
				
					this->m_current_token.kind = Kind::variable;
					return this->m_current_token;
				}
				else
				{
					// std::cerr << "Syntax Error " << std::endl;
					this->m_current_token = { Kind::print };
					return this->m_current_token;
				}
			}

		} // end of switch statement

	} // end of fetch_next_token()
}


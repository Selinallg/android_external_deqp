#ifndef _GLUDEFS_HPP
#define _GLUDEFS_HPP
/*-------------------------------------------------------------------------
 * drawElements Quality Program OpenGL ES Utilities
 * ------------------------------------------------
 *
 * Copyright 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *//*!
 * \file
 * \brief OpenGL ES Test Utility Library.
 *//*--------------------------------------------------------------------*/

#include "tcuDefs.hpp"

// Macros for checking API errors.
#define GLU_EXPECT_NO_ERROR(ERR, MSG)	glu::checkError((ERR), MSG, __FILE__, __LINE__)
#define GLU_CHECK_ERROR(ERR)			GLU_EXPECT_NO_ERROR(ERR, DE_NULL)
#define GLU_CHECK_MSG(MSG)				GLU_EXPECT_NO_ERROR(glGetError(), MSG)
#define GLU_CHECK()						GLU_CHECK_MSG(DE_NULL)
#define GLU_CHECK_CALL_ERROR(CALL, ERR)	do { CALL; GLU_EXPECT_NO_ERROR(ERR, #CALL); } while (deGetFalse())
#define GLU_CHECK_CALL(CALL)			do { CALL; GLU_EXPECT_NO_ERROR(glGetError(), #CALL); } while (deGetFalse())


/*--------------------------------------------------------------------*//*!
 * \brief OpenGL (ES) utilities
 *//*--------------------------------------------------------------------*/
namespace glu
{

class RenderContext;

class Error : public tcu::TestError
{
public:
					Error				(int error, const char* message, const char* expr, const char* file, int line);
					Error				(int error, const std::string& message);
	virtual			~Error				(void) throw();

	int				getError			(void) const { return m_error; }

private:
	int				m_error;
};

class OutOfMemoryError : public tcu::ResourceError
{
public:
					OutOfMemoryError	(const char* message, const char* expr, const char* file, int line);
					OutOfMemoryError	(const std::string& message);
	virtual			~OutOfMemoryError	(void) throw();
};

void checkError (deUint32 err, const char* msg, const char* file, int line);
void checkError (const RenderContext& context, const char* msg, const char* file, int line);

} // glu

#endif // _GLUDEFS_HPP

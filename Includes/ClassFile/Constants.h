/*nimh-doc
 *= Includes/ClassFile/Constants.h
 * Author: %(KatrinaTheLamia)user
 * Project: %(JavaKitty)project %(Jerl6)project %(Jython3)project %(HTCemu)project
 * Groups: %(NIMHLabs) %(Perl6) %(RaddTeam) %(TeamTemporal)
 * Creation: 3176-2-62
 *
 * Define the in memory information in the Constants section of the class file
 *
 * == Revisions:
 * + 3176-2-62 Initial Creation
 * ~ 3176-5-28 Update the comments to fit the proper name
 * ! 3176-5-28 File still dangerously stupid
 * + 3176-5-30 Access constants added
 * + 3176-5-30 Fixed header file issues
 * + 3176-5-30 Add guards for C++
 * ~ 3176-5-30 Made file less retarded
 *
 * == TODO
 * ! Make file suck a lot less
 *
 */


/*
 * Start header
 */
#ifndef __JK_ClassFile_Constants_H__
#define __JK_ClassFile_Constants_H__

/*
 * C++ Guards, naturally.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *
 * An enum for numerical type constants.
 *
 */
enum JK_Constant_Type 
{
	jk_t_utf8 = 1,
	jk_t_interger = 3,
	jk_t_float = 4,
	jk_t_long = 5,
	jk_t_double = 6,
	jk_t_class = 7,
	jk_t_string = 8,
	jk_t_field_reference = 9,
	jk_t_method_reference = 10,
	jk_t_interface_method_reference = 11,
	jk_t_name_and_type = 12,
};

/*
 * Access constants
 * Flags for Class Files to dictate access.
 */

enum JK_Constant_Type 
{
	jk_access_is_public = 0x0001,
	jk_access_is_finale = 0x0010,
	jk_access_is_super = 0x0020,
	jk_access_is_interface = 0x0100,
	jk_access_is_abstract = 0x0200,
};


/*
 * The actual varients of Constants stilll need to be defined
 *
 */
typedef struct 
{
	JK_Constant_Type tag;
	void *constant_internals;
} JK_Constant_dat JK_Constant;

#ifdef __cplusplus
};
#endif

#endif /* End the header */

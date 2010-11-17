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
 *
 * == TODO
 * ! Make file suck a lot less
 *
 */

enum JK_Constant_Type {
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
 * Quick notes before passing out:
 * Since this is meant for internal memory purposes, the internals to the 
 * constant will be elaborated elsewhere
 *
 *
 */
typedef struct {
	JK_Constant_Type tag;
	void *constant_internals;
} JK_Constant_dat JK_Constant;

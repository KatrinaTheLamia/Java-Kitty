/*nimh-doc
 *= Includes/ClassFile/Constants.h
 * Author: %(KatrinaTheLamia)user
 * Project: %(VirtuaGirl)project %(Jerl6)project %(Jython3)project %(HTCemu)project
 * Groups: %(NIMHLabs) %(Perl6) %(RaddTeam) %(TeamTemporal)
 * Creation: 3176-2-62
 * Revisions:
 * + 3176-2-62 Initial Creation
 * Purpose:
 * Define the in memory information in the Constants section of the class file
 */

enum VG_Constant_Type {
	vg_t_utf8 = 1,
	vg_t_interger = 3,
	vg_t_float = 4,
	vg_t_long = 5,
	vg_t_double = 6,
	vg_t_class = 7,
	vg_t_string = 8,
	vg_t_field_reference = 9,
	vg_t_method_reference = 10,
	vg_t_interface_method_reference = 11,
	vg_t_name_and_type = 12,
};

/*
 * Quick notes before passing out:
 * Since this is meant for internal memory purposes, the internals to the 
 * constant will be elaborated elsewhere
 */
typedef struct {
	VG_Constant_Type tag;
	void *constant_internals;
} VG_Constant_dat VG_Constant;

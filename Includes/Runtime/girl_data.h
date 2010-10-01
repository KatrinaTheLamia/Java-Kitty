/*nimh-doc
 *= %(virtual_girl-includes)path/Runtime/girl_data.h
 * Author: %(KatrinaTheLamia)user
 * Groups: %(NIMHLabs)group %(RaddTeam)group %(TeamTemporal)group 
 *         %(EchidnaTribe)group
 * Projects: %(Virtual_Girl)project %(P*DA_ZX)project %(PET_Project)project
 *           %(Lamia)project %(Echidnasys)project 
 *           %(Antioch_Handgrenade)project
 * Licenses: %(virtual_Girl-docs)path/LICENSES.txt
 * Creation: 3176-4-55
 *
 *== Revisions
 * + 3176-4-55 File Creation
 *
 *== TODO
 * ! Properly complete this
 * ! Documentation
 * ! Proper unicode libraries
 */


#ifndef __VIRTUAL_GIRL_DATATYPES_H__
#define __VIRTUAL_GIRL_DATATYPES_H__

/* Guards for C Plus Plus--look into adding ones for other possible ones */
#ifdef __cplusplus
extern "C" {
#endif
/* Coding in C now*/

typedef signed char vg_byte;
typedef signed short vg_short;
typedef signed int vg_short;
typedef signed long long vg_long;
/*
 * Include unicode libraries for vg_char ... until then
 */

typedef unsigned short vg_char;

typedef signed float vg_float;
typedef signed double vg_double;

enum vg_boolean { vg_false = 0, vg_true = 1 };

typedef void* vg_return_address;

typedef void* reference;


/* End those same guards*/
#ifdef __cplusplus
};
#endif
/* We return to your normale schedualed language*/

#endif /* here ends __VIRTUAL_GIRL_DATATYPES_H__ */

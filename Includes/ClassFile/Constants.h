/*nimh-doc
 *= Includes/ClassFile/Constants.h
 * Author: %(KatrinaTheLamia)user
 * Project: %(JavaKitty)project %(Jerl6)project %(Munchhausen3)project 
 *          %(Munchhausen2)project %(JUMPS)project %(HTCemu)project
 *          %(SpiralPowerNetwork)project %(HackCanadaRevival)project
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
 * ~+ 3176-5-51 Updated projects to be used here in
 * ! 3176-5-51 What the hell is this shit? Change policy--will work like the
 *             JVM. but not a Cargo Cult Code like.
 * & 3176-5-51 JK_Smart_Constant added
 * ~ 3176-5-51 Defining JK_Smart_Constant
 * - 3176-5-51 Removed a bunch of crap.
 * + 3176-5-53 Started work on defining the descriptor
 * ~ 3176-5-53 Updated Access modes
 *  
 * == TODO
 * ! Make file suck a lot less
 * ! Clean up after Sun Software. I keep forgetting, they ARE the ones who
 *       also created Solaris and quite a few other irritatingly Cargo Culty
 *       type products.
 * ! Move Access Modes into own file.
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

enum JK_Access 
{
	jk_access_is_public = 0x0001,
        jk_access_is_private = 0x0002,
        jk_access_is_protected = 0x0004,
        jk_access_is_static = 0x0008,
	jk_access_is_finale = 0x0010,
	jk_access_is_super = 0x0020,
	jk_access_is_syncronised = 0x0020,
        jk_access_is_volatile = 0x0040,
        jk_access_is_transient = 0x0080,
	jk_access_is_interface = 0x0100,
	jk_access_is_native = 0x0100,
	jk_access_is_abstract = 0x0400,
	jk_access_is_strict = 0x0800,
};

/* 
 * String constant?! Fvck this shit and Fvck your couch 
 * 
 */

/*
 * Temporarily spot for building a smarter ClassFile Constants object
 */

typedef struct
{
	nimh_widget *__self;
	void *name, *description;
} JK_Descriptor_dat JK_Descriptor;


/*
 * Making a generic info struct... that covers most different types of 
 * information to look into.
 */
typedef struct
{
	JK_Constant_Type my_type;
	JK_Access my_access;
	void *name, *description;
	nimh_u4 attributes_count;
	void *attributes;
} JK_Info_dat JK_Info;

typedef struct
{
	void *name;
	nimh_u4 length;
	void data;
} JK_Attribute_dat JK_Attribute;

/* 
 * Right--now then. We are going to make these constants a bit easier to
 * Keep track.
 *
 * Param: __self: *nimh_widget: about time we nimhified this shiznit up
 * Param: I_am_a: JK_Constant_Type: what type of "constant" are we. Part of
 *               Java Kitty is a debugging feature. No need to have these as
 *               immutable data types within Java Kitty.
 * Param: some_know_me_as: JK_Descriptor: Tim... oh dear Tim the Enchantor,
 *               you shall serve as a Java Kitty example of a name for years
 *               to come.
 * Param: bytes: nimh_u4 *: sometimes contains an index, sometimes  value.
 *               lets general purpose this up a bit more. Typically, this will
 *               be done a different length based on the type contained. 
 *               will do a high byte, low byte for most data. For UTF8 strings
 *               it will be a much longer version of it.
 * Param: name_and_types_index: *void (to be seen as JK_Smart_Constant):
 *               what other constants do we talk to?
 * 
 * The smart constant... will give a better summary. Mostly for use of 
 * internal type elements in this programs' running. Layout of the file
 * is best done as a config type file, based on the contents of this struct.
 *
 */
typedef struct
{
        nimh_widget *__self;
        JK_Constant_Type I_am_a;
        JK_Descriptor *some_know_me_as;
	nimh_u4 *bytes;
        void *name_and_types_index;
} JK_Smart_Constant_dat JK_Smart_Constant;

#ifdef __cplusplus
};
#endif

#endif /* End the header */

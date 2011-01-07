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
 * + 3176-1-6 Started Attribute work
 * ~ 3177-1-7 why the hell were name index entries not stored as nimh_strings?
 * ~ 3177-1-7 also, why am I doing this retarded stuff with void* instead of
 * 		nimh_widget... which is the same thing... just with crap 
 * 		control
 * ! 3177-1-7 Dear sweet Merciless Eris, I may have to do up my own specs 
 * 		describing the stuff I made less excessively retarded in Sun 
 * 		Microsystem's Designs. The Java Kitty 0.1 Specs, a JVM for
 * 		those distracted by shiny objects... or something
 * & 3177-1-7 Smart Attribute placeholder... I think a better name is needed 
 * 		for these Java Kitty internal types... something indicating 
 * 		the improved crap control I am giving this crap.
 * + 3177-1-7 Added exception workings... this will likely be removed.
 * ! 3177-1-7 This likely will be turned into the ClassFile.h file, 
 * 		rather than a file included by it.
 * +& 3177-1-7 Think I figured out how to not have the Attributes item quite 
 * 		as retarded.
 * +& 3177-1-7 We now have a Code Attributes specialisation.
 * + 3177-1-7 Innerclass data items added... we could nimhify this a bit more
 * 		in a later commit.
 * ~& 3177-1-77 Now working on nimhifying this file a bit more. Finally, it 
 * 		is starting to gain IQ points.
 *
 *
 * == TODO
 * ! Make file suck a lot less
 * ! Clean up after Sun Software. I keep forgetting, they ARE the ones who
 *       also created Solaris and quite a few other irritatingly Cargo Culty
 *       type products.
 * & 3177-1-7 ! Move Access Modes into own file -> This will just be the 
 * 			Classfile.h file... it really does not need to be more
 * 			spread out.
 * ! Rearrange data types to be more logically layed out for libNIMH...
 * 		just a suggestion. This is a Classfile, we can give it custom
 * 		instructions on how to lay itself out.
 * ! Comment this file better. Most of it will likely be described in the 
 * 		Java Kitty Specs... but that is more how this crap will be
 * 		used, when talking to the JVM.
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
	nimh_string *name;
	nimh_widget *description;
} JK_Descriptor_dat JK_Descriptor;


/*
 * Making a generic info struct... that covers most different types of 
 * information to look into.
 */
typedef struct
{
	nimh_widget *__self;
	JK_Descriptor *__parent;
	JK_Constant_Type my_type;
	nimh_u2 my_access;
	nimh_u4 attributes_count;
	nimh_widget *attributes;
} JK_Info_dat JK_Info;

/* Notes, Smart Attribute will likely have Code Attributes be
 * inherited from Exception Attributes*/

typedef struct
{
	nimh_widget *__self;
	nimh_Info *__parent;
	nimh_string *attribute_type;
	nimh_u4 length;
	nimh_widget *specialised_elements;
	nimh_u2 contents_count;
	nimh_widget *my_contents;
	nimh_u2 my_attribute_counts;
	nimh_widget *my_attributes;
} JK_Smart_Attribute_dat JK_Smart_Attribute;

/*
 * Specialised Attribute additions for Code Attributes;
 */
typedef struct {
	nimh_widget *__self;
	JK_Smart_Attribute *__parent;
	nimh_string *name;
	nimh_stack_point max_stack;
	nimh_u2 max_locals;
	nimh_u4 code_length;
	nimh_u1 *code_block;
} JK_Code_Attribute_Variances_dat JK_Code_Attribute_Variances;

typedef struct
{
	nimh_widget *__self;
	JK_Info *__parent, outer_info;
} JK_Innerclass_Entry_dat JK_Innerclass_Entry;

typedef struct
{
	nimh_widget *__self;
	nimh_stack_point start, end, handler;
	nimh_string catch_type;
} JK_Exception_Entry_dat JK_Exception_Entry;

typedef struct
{
	nimh_widget *__self;
	nimh_stack_point start, end;
	nimh_u4 line_number;
} JK_LineNumber_Entry_dat JK_LineNumber_Entry;

typedef struct
{
	nimh_widget *__self;
	nimh_Info *__parent;
	nimh_stack_point start, index;
} JK_Lexical_Entry_dat JK_Lexical_Entry;

/* 
 * Right--now then. We are going to make these constants a bit easier to
 * Keep track.
 *
 * Param: __self: *nimh_widget: about time we nimhified this shiznit up
 * Param: __parent: *JK_Descriptor: moved this into parent's spot. It is a 
 * 		shame. Before as a "some_know_me_as" allowed for an excellent
 * 		set of examples refering to Tim the Enchantor.
 * Param: I_am_a: JK_Constant_Type: what type of "constant" are we. Part of
 *               Java Kitty is a debugging feature. No need to have these as
 *               immutable data types within Java Kitty.
 * Param: bytes: nimh_u4 *: sometimes contains an index, sometimes  value.
 *               lets general purpose this up a bit more. Typically, this will
 *               be done a different length based on the type contained. 
 *               will do a high byte, low byte for most data. For UTF8 strings
 *               it will be a much longer version of it.
 * Param: name_and_types_index: *nimh_widget (will point to the 
 *               JK_Smart_Constant): what other constants do we talk to?
 * 
 * The smart constant... will give a better summary. Mostly for use of 
 * internal type elements in this programs' running. Layout of the file
 * is best done as a config type file, based on the contents of this struct.
 *
 */
typedef struct
{
        nimh_widget *__self;
	JK_Descriptor *__parent;
        JK_Constant_Type I_am_a;
	nimh_u4 *bytes;
        nimh_widget *names_and_types_index;
} JK_Smart_Constant_dat JK_Smart_Constant;

/*
 * Note for the future, this is mostly internal information on the classfile.
 * For writing to the classfile, another file, a layout file, will be used.
 * The Layout file will note any constraints in writing the file. When reading
 * the files, all that will be considered is security constraints (which will
 * be modifiable based on libNIMH configuration settings).
 *
 * Yeah, Sun Microsystems--things do not need to be as formal as you are 
 * having them be. JVM-san, meet Java Kitty-chan X3. ^n.n;7
 *
 */
typedef struct
{
	nimh_widget *__self;
	nimh_number magic;
	nimh_number major_version, minor_version;
	nimh_widget *__this_class, *__super;
	nimh_number *constant_pool_size, interface_count, field_count, methods_count, attributes_count;
	JK_Smart_Constant *constant_pool;
	nimh_u2 access;
	JK_Smart_Attributes *attributes;
	JK_Info *my_information;
} JK_Smart_ClassFile_dat JK_Smart_ClassFile;


#ifdef __cplusplus
};
#endif

#endif /* End the header */

/*nimh-doc
 *= %(Java_Kitty-Include)path/ClassFile.h
 * Projects: %(Java_Kitty)project, %(Jerl6)project, %(Jython3)project
 * 		%(Munchhausen2)project, %(JUMPS)project, 
 * 		%(Market_Income)projects
 * Maintainer: %(KatrinaTheLamia)user
 * Groups: %(NIMHLabs)group
 * Creation: 3176-2-34
 * License: %(Virtual-Girl-Docs)path/LICENSE.txt
 *
 * Generic strucutre file for a ClassFile following the JVM Spec
 *
 *== Revisions
 * + 3176-2-34 file creation
 * ! 3176-2-34 Attributes section needs repair
 * ~ 3176-2-57 libNIMHified this with class
 * ~ 3176-5-26 Brand name change, updating comments
 *
 *== TODO
 * ! 3176-2-57 Debug
 * ! 3176-2-57 Implement prototypes
 */

#ifndef __Java_Kitty_ClassFile_H__
#define __Java_Kitty_ClassFile_H__

#ifdef __cplusplus /*Oh hi guy--we are actually a C header*/
extern "C" {
#endif /*Yeah--just figured you'd need a little help there guy*/

/*nimh-doc
 * Class: JK_ClassFile
 * Field: __parent: nimh_widget: libNIMH Garbage collection and information
 * Field: magic: nimh_u32b: typically a 32 bit magic number.
 * Field: major_version: nimh_number: major version of this class, assumed to be 16bit
 * Field: minor_version: nimh_number: minor version of this class, assumed to be 16bit
 * Field: thisclass: void (assumed to be VG_ClassFile): pointer to this class
 * Field: superclass: void (assumed to be VG_ClassFile): pointe to this class' parent
 * Field: constant_pool_count: nimh_number: size of the constant pool. Assumed to be less than 65536
 * Field: interfaces_count: nimh_number: number of the interfaces. Assumed to be less than 65536
 * Field: field_count: nimh_number: number of the fields. Assumed to be less than 65536
 * Field: methods_count: nimh_number: number of fields. Assumed to be less than 65536
 * Field: attributes_count: nimh_number: number of attributes. Assumed to be less than 65536
 * Field: constant_pool: JK_Constant_pool: a double linked list of constants
 * Field: access_flags: JK_Access: access flags for this particular class file
 * Field: interfaces: JK_interfaces: interfaces present in this class
 * Field: fields: JK_Fields: a compendium of the literary mistakes through out Shakespearian classics.
 * Field: methods: JK_Methods: the methods that this classfield uses.
 * Field: attributes: JK_Attributes: attributes given to this classfile
 */
typedef struct {
    nimh_widget *__parent;
    nimh_number *magic;
    nimh_number *major_version, *minor_version;
    void *thisclass, *superclass;
    nimh_number *constant_pool_count, *interfaces_count, *field_count, *methods_count, *attributes_count;
    JK_Constant *constant_pool;
    JK_Access *access_flags;
    JK_Interfaces *interfaces;
    JK_Fields *fields;
    JK_Methods *methods;
    JK_Attributes *attributes;
} JK_Class_data JK_Class;

/*nimh-doc:
 * Method: JK_Class
 * Param: nimh_book: the book that this classfile is in.
 * Param: nimh_string: the name to access this classfile with
 * Param: nimh_number: major version number
 * Param: nimh_number: minor version number
 * Returns: nimh_book: pointer to the nimh_book containing the Virtual Girl Class File
 * constructor method
 */
nimh_book *JK_Class(nimh_book*,nimh_string*,nimh_number*,nimh_number*);

/*nimh-doc:
 * Method: JK_Class
 * Param: nimh_book: current book of the class file
 * Param: nimh_string: the classfile to be copied into
 * Param: nimh_book: book of the target class file
 * Param: nimh_string: the classfile to be copied from
 */
nimh_book *JK_Class(nimh_book*,nimh_string*,nimh_book*,nimh_string*);

/*nimh-doc:
 * Method: JK_major
 * Method: JK_minor
 * Param: nimh_book: the book that this classfile is in.
 * Param: nimh_string: the class file we are grabbing
 * Param: nimh_number: optional: a new version number
 * Return: nimh_number: the version
 * Purpose:
 * /[GS]et/ the version number
 */
nimh_number *JK_major(nimh_book*,nimh_string*,nimh_number*=nil);
nimh_number *JK_minor(nimh_book*,nimh_string*,nimh_number*=nil);

/*nimh-doc:
 * Method: this_class
 * Method: super_class
 * Param: nimh_book: the book that this classfile is in
 * Param: nimh_string: the name of the class file we are talking about
 * Param: JK_Class: optional: new class to switch this class file into
 * Returns: JK_Class: the requested Class File
 * Purpose:
 * Possibly broken /[GS]et/ method for this_class and super_class
 */
JK_Class *this_class(nimh_book*,nimh_string*,JK_Class*=nil);
JK_Class *super_class(nimh_book*,nimh_string*,JK_Class*=nil);

/*nimh-doc:
 * Method: constant
 * Param: nimh_book: the book that this class file is in
 * Param: nimh_string: the name of the class file we are wanting.
 * Param: nimh_string: the name of the constant we want to talk to
 * Param: JK_Constant: a constant pool entry that is to be used
 * Return: JK_Constant
 * Purpose:
 * A /[GS]et/ function for the constant pool
 */
JK_Constant *constant(nimh_book*,nimh_string*,nimh_string*,JK_Constant*=nil);

/*nimh-doc:
 * Method: add
 * Method: remove
 * Param: nimh_book: this class' book
 * Param: nimh_string: the VG_Class' name
 * Param: JK_Access: the access flags to mess with
 * Return: current access flags
 * Purpose:
 * Add and remove various access flags from this class
 */

JK_Access *add(nimh_book*,nimh_string*,JK_Access*);
JK_Access *remove(nimh_book*,nimh_string*,JK_Access*);

/*nimh-doc:
 * Method: interface
 * Param: nimh_book: a brief history of the sexual exploits of the royal family
 * Param: nimh_string: name of the class we are messing with
 * Param: nimh_string: a name for our interface
 * Param: JK_Interface: optional: an interface to substitute into here.
 * Returns: JK_Interface
 * Purpose:
 * To get Prez elected as student president.
 *
 * I mean, a /[GS]et/ function for the classes interfaces
 */

JK_Interface *interface(nimh_book*,nimh_string*,nimh_string*,JK_Interface*=nil);

/*nimh-doc:
 * Method: field
 * Param: nimh_book: the book we are to grab stuff from
 * Param: nimh_string: the class we want to inspect
 * Param: nimh_string: the id of field we want to talk to
 * Param: JK_Field: optional: some field we can put in
 * Returns: JK_Field
 * Purpose
 * A /[GS]et/ function
 */
JK_Field *field(nimh_book*,nimh_string*,nimh_string*,JK_Field*=nil);

/*nimh-doc:
 * Method: method
 * Param: nimh_book: a list of trade secrets on the white slave black market
 * Param: nimh_string: our Class File we want
 * Param: nimh_string: the name of our target method
 * Param: JK_Method: optional: method to substitute in
 * Return: JK_Method
 * Purpose:
 * Another /[GS]et/ function. But this time WITH FEELING!
 */
JK_Method *method(nimh_book*,nimh_string*,nimh_string*,JK_Method*=nil);

/*nimh-doc:
 * Method: attribute
 * Param: nimh_book: the book we are dealing ith
 * Param: nimh_string: the name of our class file
 * Param: JK_Attribute: optional: a VG_Attribute to put into this listing
 * Return: JK_Attribute
 * Purpose:
 * Attribute /[GS]et/ function.
 */
JK_Attribute *attribute(nimh_book*,nimh_string*,JK_Attribute*=nil);

#ifdef __cplusplus /*oh, hi guy, you need to close up here. */
}
#endif /* there you go, guy */

#endif // __Virtual_Girl_ClassFile_H__



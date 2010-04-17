/*nimh-doc
 * File: %(Virtual-Girl-Include)path/ClassFile.h
 * Projects: Virtual Girl, Jerl 6, Jython 3
 * Maintainer: %(KatrinaTheLamia)user
 * Groups: %(NIMHLabs)group
 * Creation: 3176-2-34
 * Revisions:
 * + 3176-2-34 file creation
 * ! 3176-2-34 Attributes section needs repair
 * Purpose:
 * Generic structure file for a ClassFile in the JVM spec
 */

#ifndef __Virtual_Girl_ClassFile_H__
#define __Virtual_Girl_ClassFile_H__

/*nimh-doc
 * Class: VG_ClassFile
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
 * Field: constant_pool: VG_Constant_pool: a double linked list of constants
 * Field: access_flags: VG_Access: access flags for this particular class file
 * Field: interfaces: VG_interfaces: interfaces present in this class
 * Field: fields: VG_Fields: a compendium of the literary mistakes through out Shakespearian classics.
 * Field: methods: VG_Methods: the methods that this classfield uses.
 * Field: attributes: VG_Attributes: attributes given to this classfile
 */
typedef struct {
    nimh_number *magic;
    nimh_number *major_version, *minor_version;
    void *thisclass, *superclass;
    nimh_number *constant_pool_count, *interfaces_count, *field_count, *methods_count, *attributes_count;
    VG_Constant *constant_pool;
    VG_Access *access_flags;
    VG_Interfaces *interfaces;
    VG_Fields *fields;
    VG_Methods *methods;
    VG_Attributes *attributes;
} VG_Class_data VG_Class;

/*nimh-doc:
 * Method: VG_Class
 * Param: nimh_book: the book that this classfile is in.
 * Param: nimh_string: the name to access this classfile with
 * Param: nimh_number: major version number
 * Param: nimh_number: minor version number
 * Returns: nimh_book: pointer to the nimh_book containing the Virtual Girl Class File
 * Purpose: constructor method
 */
nimh_book *VG_Class(nimh_book*,nimh_string*,nimh_number*,nimh_number*);

/*nimh-doc:
 * Method: VG_Class
 * Param: nimh_book: current book of the class file
 * Param: nimh_string: the classfile to be copied into
 * Param: nimh_book: book of the target class file
 * Param: nimh_string: the classfile to be copied from
 */
nimh_book *VG_Class(nimh_book*,nimh_string*,nimh_book*,nimh_string*);

/*nimh-doc:
 * Method: VG_major
 * Method: VG_minor
 * Param: nimh_book: the book that this classfile is in.
 * Param: nimh_string: the class file we are grabbing
 * Param: nimh_number: optional: a new version number
 * Return: nimh_number: the version
 * Purpose:
 * /[GS]et/ the version number
 */
nimh_number *VG_major(nimh_book*,nimh_string*,nimh_number*=nil);
nimh_number *VG_minor(nimh_book*,nimh_string*,nimh_number*=nil);

/*nimh-doc:
 * Method: this_class
 * Method: super_class
 * Param: nimh_book: the book that this classfile is in
 * Param: nimh_string: the name of the class file we are talking about
 * Param: VG_Class: optional: new class to switch this class file into
 * Returns: VG_Class: the requested Class File
 * Purpose:
 * Possibly broken /[GS]et/ method for this_class and super_class
 */
VG_Class *this_class(nimh_book*,nimh_string*,VG_Class*=nil);
VG_Class *super_class(nimh_book*,nimh_string*,VG_Class*=nil);

/*nimh-doc:
 * Method: constant
 * Param: nimh_book: the book that this class file is in
 * Param: nimh_string: the name of the class file we are wanting.
 * Param: nimh_string: the name of the constant we want to talk to
 * Param: VG_Constant: a constant pool entry that is to be used
 * Return: VG_Constant
 * Purpose:
 * A /[GS]et/ function for the constant pool
 */
VG_Constant *constant(nimh_book*,nimh_string*,nimh_string*,VG_Constant*=nil);

/*nimh-doc:
 * Method: add
 * Method: remove
 * Param: nimh_book: this class' book
 * Param: nimh_string: the VG_Class' name
 * Param: VG_Access: the access flags to mess with
 * Return: current access flags
 * Purpose:
 * Add and remove various access flags from this class
 */

VG_Access *add(nimh_book*,nimh_string*,VG_Access*);
VG_Access *remove(nimh_book*,nimh_string*,VG_Access*);

/*nimh-doc:
 * Method: interface
 * Param: nimh_book: a brief history of the sexual exploits of the royal family
 * Param: nimh_string: name of the class we are messing with
 * Param: nimh_string: a name for our interface
 * Param: VG_Interface: optional: an interface to substitute into here.
 * Returns: VG_Interface
 * Purpose:
 * To get Prez elected as student president.
 *
 * I mean, a /[GS]et/ function for the classes interfaces
 */

VG_Interface *interface(nimh_book*,nimh_string*,nimh_string*,VG_Interface*=nil);

/*nimh-doc:
 * Method: field
 * Param: nimh_book: the book we are to grab stuff from
 * Param: nimh_string: the class we want to inspect
 * Param: nimh_string: the id of field we want to talk to
 * Param: VG_Field: optional: some field we can put in
 * Returns: VG_Field
 * Purpose
 * A /[GS]et/ function
 */
VG_Field *field(nimh_book*,nimh_string*,nimh_string*,VG_Field*=nil);

/*nimh-doc:
 * Method: method
 * Param: nimh_book: a list of trade secrets on the white slave black market
 * Param: nimh_string: our Class File we want
 * Param: nimh_string: the name of our target method
 * Param: VG_Method: optional: method to substitute in
 * Return: VG_Method
 * Purpose:
 * Another /[GS]et/ function. But this time WITH FEELING!
 */
VG_Method *method(nimh_book*,nimh_string*,nimh_string*,VG_Method*=nil);

/*nimh-doc:
 * Method: attribute
 * Param: nimh_book: the book we are dealing ith
 * Param: nimh_string: the name of our class file
 * Param: VG_Attribute: optional: a VG_Attribute to put into this listing
 * Return: VG_Attribute
 * Purpose:
 * Attribute /[GS]et/ function.
 */
VG_Attribute *attribute(nimh_book*,nimh_string*,VG_Attribute*=nil);

#endif // __Virtual_Girl_ClassFile_H__



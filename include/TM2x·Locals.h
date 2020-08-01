#ifndef TM2X_LOCALS_H
#define TM2X_LOCALS_H

/*
  This is not a traditional header, and can not be used as such.

  #include this file inside of a Locals union with other conveyance's locals .h files. 

  union{
   ...
   #include "TM2x·Locals"
  }Locals;

*/

    struct{
      TM2x *tape;
      continuation nominal;
      continuation fail;
    } TM2x·alloc_heap;
#if 0
    struct{
      TM2x *tape;
      address_t byte_n;   // extent of the array, in bytes
      continuation nominal;
      continuation alloc_fail;

      address_t alloc_byte_n;

    } TM2x·construct_bytes;

    struct{
      TM2x *tape;
      address_t element_n;  // extent of the array, in elements
      address_t element_byte_n; // extent of the element, in bytes
      continuation nominal;
      continuation index_gt_n;
      continuation alloc_fail;

      address_t byte_n;
    } TM2x·construct_elements;

    struct{
      TM2x *tape;
      TM2x *tape_source;
      continuation nominal;
      continuation fail;
    } TM2x·construct_write;

    struct{
      TM2x *tape;
      void *source_pt;
      address_t byte_n;
      continuation nominal;
      continuation fail;
    } TM2x·construct_write_bytes;

    struct{
      TM2x *tape;
      void *source_pt;
      address_t element_n;
      address_t element_byte_n;
      continuation nominal;
      continuation index_gt_n;
      continuation fail;

      address_t byte_n;
    } TM2x·construct_write_elements;

    struct{
      TM2x *tape;
      TM2x *tape_source;
      continuation nominal;
      continuation fail;
    } TM2x·construct_write_TM2x;

    /* copy_bytes does not make use of other continuations, and does not have local vars.
    struct{
      TM2x *src;
      address_t src_byte_i;
      TM2x *dst;
      address_t dst_byte_i;
      address_t byte_n;
      continuation nominal;
      continuation src_index_gt_n;
      continuation dst_index_gt_n;
    } TM2x·copy_bytes;
    */

    struct{
      TM2x *src;
      address_t src_element_i;
      TM2x *dst;
      address_t dst_element_i;
      address_t element_n;  // index of nth element of the copy region
      address_t element_byte_n;
      continuation nominal;
      continuation alloc_fail;
      continuation src_index_gt_n;
      continuation dst_index_gt_n;
    } TM2x·copy_elements;

    struct{
      TM2x **tape;
      continuation nominal;
    } TM2x·dealloc_heap;

    struct{
      TM2x *tape;
      continuation nominal;
    } TM2x·destruct;

    struct{
      TM2x *tape;
      address_t index;
      address_t element_n;
      address_t element_byte_n;
      void *dst_element_pt;
      continuation nominal;
      continuation index_gt_n;
    } TM2x·index·read;

    struct{
       TM2x *tape ;
       address_t index;
       address_t element_byte_n;
       void **pt;
       continuation nominal;
       continuation index_gt_n;
    } TM2x·index·to_pt;

    struct{
       TM2x *tape;
       address_t element_byte_n;
       continuation nominal;
       continuation pop_last;
       continuation alloc_fail;
    } TM2x·pop;

    struct{
      TM2x *tape;
      void *element_base_pt;
      address_t element_byte_n;
      continuation nominal;
      continuation alloc_fail;
    } TM2x·push;

    struct{
      TM2x *tape;
      void *source_pt;
      address_t source_byte_n;
      continuation nominal;
      continuation alloc_fail;
    } TM2x·push_bytes;

    struct{
      TM2x *tape ;
      void *base_pt;
      address_t element_n ;
      address_t element_byte_n ;
      continuation nominal;
      continuation alloc_fail;
      continuation index_gt_n;
     } TM2x·push_elements;

    struct{
      TM2x *tape ;
      TM2x *tape_source;
      continuation nominal;
      continuation alloc_fail;
    } TM2x·push_TM2x;

    struct{
       TM2x *tape ;
       void *dst_element_pt ;
       address_t element_byte_n;
       continuation nominal;
       continuation pop_last;
       continuation alloc_fail;
    } TM2x·read_pop;

    struct{
      TM2x *tape;
      address_t after_byte_n;
      continuation nominal;
      continuation alloc_fail;
    } TM2x·resize_bytes;

    struct{
      TM2x *tape;
      address_t after_element_n;
      address_t element_byte_n;
      continuation nominal;
      continuation alloc_fail;
      continuation index_gt_n;
    } TM2x·resize_elements;

    struct{
      void *src_pt;
      TM2x *dst;
      address_t dst_byte_i;
      address_t byte_n;
      continuation nominal;
      continuation alloc_fail;
      continuation src_index_gt_n;
      continuation dst_index_gt_n;
    } TM2x·write_bytes;

#endif

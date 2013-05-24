#include <ruby.h>
#include "libthumb.h"

static VALUE rb_cThumbnail;

static VALUE thumb_alloc(VALUE klass)
{
  return Data_Wrap_Struct(klass, 0, thumb_free, 0);
}

static VALUE thumb_s_read(VALUE klass, VALUE path)
{
  THUMB_DATA *thumb;

  if((thumb = thumb_read(StringValuePtr(path))) != NULL &&
      thumb->data != NULL &&
      thumb->length != 0)
    return Data_Wrap_Struct(klass, 0, thumb_free, thumb);
  else
    return Qnil;
}

static VALUE thumb_data(VALUE klass)
{
  THUMB_DATA *thumb;

  Data_Get_Struct(klass, THUMB_DATA, thumb);

  return rb_str_new((char *)thumb->data, thumb->length);
}

static VALUE thumb_length(VALUE klass)
{
  THUMB_DATA *thumb;

  Data_Get_Struct(klass, THUMB_DATA, thumb);

  return INT2FIX(thumb->length);
}

static VALUE thumb_orientation(VALUE klass)
{
  THUMB_DATA *thumb;

  Data_Get_Struct(klass, THUMB_DATA, thumb);

  return INT2FIX(thumb->orientation);
}

void Init_exif_thumbnail(void)
{
  rb_cThumbnail = rb_define_class("EXIFThumbnail", rb_cObject);
  rb_define_alloc_func(rb_cThumbnail, thumb_alloc);
  rb_define_singleton_method(rb_cThumbnail, "read", thumb_s_read, 1);
  rb_define_method(rb_cThumbnail, "data", thumb_data, 0);
  rb_define_method(rb_cThumbnail, "length", thumb_length, 0);
  rb_define_method(rb_cThumbnail, "orientation", thumb_orientation, 0);
}

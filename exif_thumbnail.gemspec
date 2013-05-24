Gem::Specification.new do |s|
  s.name        = "exif_thumbnail"
  s.version     = "0.0.1"
  s.date        = "2013-05-25"
  s.summary     = "EXIF Thumbnail"
  s.description = "Read thumbnail from EXIF"
  s.author      = ["nkmrshn"]
  s.extensions  = ["ext/exif_thumbnail/extconf.rb"]
  s.files       = Dir.glob('ext/**/*.{c,h,rb}')
end

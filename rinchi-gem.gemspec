$:.unshift File.expand_path('../lib', __FILE__)
require 'rinchi-gem/version'

Gem::Specification.new do |s|
  s.name = "rinchi-gem"
  s.version = RinchiGem::GEMVERSION

  s.authors = ["Yu-Chieh Huang"]
  s.date = %q{2018-06-29}
  s.description = %q{Rinchi as a GEM}
  s.email = ["jasonych99@gmail.com"]
  s.homepage = %q{http://github.com/complat/rinchi-gem}
  s.require_paths = ["lib"]
  s.rubygems_version = %q{1.6.2}
  s.summary = %q{RinchiGem!}
  s.license = "GPL-3.0"
  s.test_files = ["test/test_rinchi_gem.rb"]

  s.files = %w{Rakefile lib/rinchi-gem.rb lib/rinchi-gem/version.rb}
  s.extensions = ['ext/rinchi-gem/extconf.rb']
end

LANGUAGE  = Java
PROJECT   = af
##############################################################################
# Dirs
MODEL     = ./model
VIEW      = ./view/$(LANGUAGE)/$(PROJECT)
SRCS      = $(shell find model/ -name \*.tmpl -printf '%f\n' )

templates = $(foreach s,$(SRCS),$(addprefix $(VIEW)/,$(s:.tmpl=.py)))
TARGETS   = $(templates)

all: $(TARGETS)

# tmpl -> py
$(VIEW)/%.py:  $(MODEL)/%.tmpl
	cheetah-compile --flat $^ --odir $(VIEW)

mklinks: rmlinks
	make -p ./view/$(LANGUAGE)/$(PROJECT)
	touch ./view/$(LANGUAGE)/__init__.py
	touch ./view/$(LANGUAGE)/$(PROJECT)/__init__.py
	@(cd $(MODEL); pwd; echo $(@); ./$(@).sh)
rmlinks:
	@(cd $(MODEL); pwd; echo $(@); ./$(@).sh)
clean:
	find . -name "*.pyc" -delete
	find . -name "*.py.bak" -delete
	rm $(templates)
	rm -rf ./view/$(LANGUAGE)


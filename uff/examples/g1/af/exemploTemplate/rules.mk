SRCS      = $(shell find model/ -name \*.tmpl -printf '%f\n' )
model     = model
view      = view/$(LANGUAGE)/$(PROJECT)

templates = $(foreach s,$(SRCS), $(addprefix $(view)/,$(s:.tmpl=.py)))
TARGETS   = $(templates)

all: links $(TARGETS)

# tmpl -> py
$(view)/%.py:  $(model)/%.tmpl
	cheetah-compile --flat $^ --odir $(view)

links:
	@(cd $(model); ./mklinks.sh)
view:
	python $(view)/view.py

clean:
	find $(view) -name "*.pyc" -delete
	find $(view) -name "*.py.bak" -delete
	rm $(templates) $(model)/*.tmpl

# END OF FILE

stuff = {}
stuff['bobo'] = 'poko'
stuff['baba'] = 'yaga'
stuff[1] = 'yaga'

print(stuff)

# to delete entries
del stuff['bobo']

print(stuff)


# -------------

countries = {
    "Taiwan": "TW",
    "United States": "USA",
    "Chile": "CH"
}

cities = {
    "TW": "Taipei",
    "USA": "Washington D.C.",
    "CH": "Santiago"
}

for country, abbrev in list(countries.items()):
    print(f"{country} is abbreviated {abbrev}")
    print(f"{country}'s capital is {cities[abbrev]}")
    

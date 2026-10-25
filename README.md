# C-Music
WIP project to create music within C

## Structure
The software will be structured as follows:
Samples - Arrays of values at the sample rate of the song (can be composed with other samples to create harmonics (data type stays as sample) or appended to other samples in series (data type stays as sample))
Envelopes - Arrays of values at the sample rate of the song, describe an envelope (can be composed with samples to create Notes, and can be appended to other envelopes to create longer envelopes)
Notes - Arrays of values at the sample rate of the song (can be appended to other notes to define a pattern)
Patterns - Arrays of notes (can be appended to other patterns to define a channel)
Channels - Arrays of patterns (can be mixed with other channels to create a song)
Songs - Arrays of values at the sample rate of the song
